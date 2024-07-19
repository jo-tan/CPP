#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <sstream>


bool _validCommand(std::string &command)
{
    std::string theCommand = command.substr(0, command.find(" "));
    static const std::set<std::string> validCommands = {"CAP","NICK","USER","MSG","JOIN", "SAY", "LEAVE", "KICK", "INVITE", "TOPIC", "MODE"};
    return validCommands.find(theCommand) != validCommands.end();
}

std::vector<std::string> _splitCommand(std::string &command)
{
    std::vector<std::string> cmdTable;
    std::string tmp;
    size_t start;
    size_t end = 0;
    while ((start = command.find_first_not_of(' ', end)) != std::string::npos) {
        end = command.find(' ', start);
        cmdTable.push_back(command.substr(start, end - start));
    }
    return cmdTable;
}

std::vector<std::string> parseCommand(std::string &command)
{
    if (_validCommand(command))
        return _splitCommand(command);
    else
        return std::vector<std::string>();
}

std::string cmdArgToString(const std::vector<std::string> &cmdVector){
    std::string ret;

    if (cmdVector.size() <= 1){
        return ret;
    }
    ret = std::accumulate(cmdVector.begin() + 1, cmdVector.end(), std::string(""), [](const std::string &a, const std::string &b)
    {return a.empty()? b: a + " " + b;});

    return ret;
}

std::string cmdVecToString(const std::vector<std::string> &cmdVector){
    std::string ret;

    if (cmdVector.size() <= 1){
        return ret;
    }
    std::ostringstream tmp;
    for(size_t i = 1; i < cmdVector.size(); ++i){
        if (i > 1){
            tmp << " ";
        }
        tmp << cmdVector[i];
    }
    return ret = tmp.str();
}

int main(){

    std::string command = "NICK bonjour    commont ca   va         ?";

    std::vector<std::string> cmdTable = parseCommand(command);
    for(int i = 0; i < cmdTable.size(); ++i)
        std::cout << "string{" << cmdTable[i] << "}: " << i << std::endl;

//     std::string test = cmdArgToString(cmdTable);
//     std::cout << "TEST STRING:" << test << std::endl;

//     std::string oss = cmdVecToString(cmdTable);
//     std::cout << "OSS STRING:" << oss << std::endl;

}

#ifndef NUMERICAL_REPLIES_HPP
#define NUMERICAL_REPLIES_HPP

void	sendServerRpl(int const client_fd, std::string client_buffer);

# define user_id(nickname, username) (":" + nickname + "!" + username + "@localhost")

# define RPL_WELCOME(user_id, nickname) (":localhost 001 " + nickname + " :Welcome to the Internet Relay Network " + user_id + "\r\n")
# define RPL_YOURHOST(client, servername, version) (":localhost 002 " + client + " :Your host is " + servername + " (localhost), running version " + version + "\r\n")
# define RPL_CREATED(client, datetime) (":localhost 003 " + client + " :This server was created " + datetime + "\r\n")
# define RPL_MYINFO(client, servername, version, user_modes, chan_modes, chan_param_modes) (":localhost 004 " + client + " " + servername + " " + version + " " + user_modes + " " + chan_modes + " " + chan_param_modes + "\r\n")
# define RPL_ISUPPORT(client, tokens) (":localhost 005 " + client + " " + tokens " :are supported by this server\r\n")

# define ERR_UNKNOWNCOMMAND(client, command) (":localhost 421 " + client + " " + command + " :Unknown command\r\n")

// INVITE
# define ERR_NEEDMOREPARAMS(client, command) (":localhost 461 " + client + " " + command + " :Not enough parameters.\r\n")
# define ERR_NOSUCHCHANNEL(client, channel) (":localhost 403 " + client + " #" + channel + " :No such channel\r\n")
# define ERR_NOTONCHANNEL(client, channel) (":localhost 442 " + client + " #" + channel + " :The user is not on this channel.\r\n")
# define ERR_USERONCHANNEL(client, nick, channel) (":localhost 443 " + client + " " + nick + " #" + channel + " :Is already on channel\r\n")
# define RPL_INVITING(user_id, client, nick, channel) (user_id + " 341 " + client + " " + nick + " #" + channel + "\r\n")
# define RPL_INVITE(user_id, invited, channel) (user_id + " INVITE " + invited + " #" + channel + "\r\n")

// JOIN
# define RPL_JOIN(user_id, channel) (user_id + " JOIN :#" +  channel + "\r\n")
# define ERR_BANNEDFROMCHAN(client, channel) ("474 " + client + " #" + channel + " :Cannot join channel (+b)\r\n")
# define ERR_BADCHANNELKEY(client, channel) ("475 " + client + " #" + channel + " :Cannot join channel (+k)\r\n")

// KICK
# define ERR_USERNOTINCHANNEL(client, nickname, channel) ("441 " + client + " " + nickname + " #" + channel + " :They aren't on that channel\r\n")
// # define ERR_CHANOPRIVSNEEDED(client, channel) ("482 " + client + " #" +  channel + " :You're not channel operator\r\n")
# define RPL_KICK(user_id, channel, kicked, reason) (user_id + " KICK #" + channel + " " + kicked + " " + reason + "\r\n")

// KILL
# define ERR_NOPRIVILEGES(client) ("481 " + client + " :Permission Denied- You're not an IRC operator\r\n")
# define RPL_KILL(user_id, killed, comment) (user_id + " KILL " + killed + " " + comment + "\r\n")

// MODE
/* user mode */
#define MODE_USERMSG(client, mode) (":" + client + " MODE " + client + " :" + mode + "\r\n")
#define ERR_UMODEUNKNOWNFLAG(client) (":localhost 501 " + client + " :Unknown MODE flag\r\n")
#define ERR_USERSDONTMATCH(client) ("502 " + client + " :Cant change mode for other users\r\n")
#define RPL_UMODEIS(client, mode) (":localhost 221 " + client + " " + mode + "\r\n")
/* channel mode */
#define MODE_CHANNELMSG(channel, mode) (":localhost MODE #" + channel + " " + mode + "\r\n")
#define MODE_CHANNELMSGWITHPARAM(channel, mode, param) (":localhost MODE #" + channel + " " + mode + " " + param + "\r\n")
#define RPL_CHANNELMODEIS(client, channel, mode) (":localhost 324 " + client + " #" + channel + " " + mode + "\r\n")
#define RPL_CHANNELMODEISWITHKEY(client, channel, mode, password) (":localhost 324 " + client + " #" + channel + " " + mode + " " + password + "\r\n")
#define ERR_CANNOTSENDTOCHAN(client, channel) ("404 " + client + " #" + channel + " :Cannot send to channel\r\n")
#define ERR_CHANNELISFULL(client, channel) ("471 " + client + " #" + channel + " :Cannot join channel (+l)\r\n")
#define ERR_CHANOPRIVSNEEDED(client, channel) (":localhost 482 " + client + " #" + channel + " :You're not channel operator\r\n")
#define ERR_INVALIDMODEPARAM(client, channel, mode, password) ("696 " + client + " #" + channel + " " + mode + " " + password + " : password must only contained alphabetic character\r\n")
// RPL_ERR a broadcoast quand user pas +v ou operator veut parler
      // dans notre cas c'était tiff (client) qui voulait send a message
      // :lair.nl.eu.dal.net 404 tiff #pop :Cannot send to channel
#define RPL_ADDVOICE(nickname, username, channel, mode, param) (":" + nickname + "!" + username + "@localhost MODE #" + channel + " " + mode + " " + param + "\r\n")

// MOTD
#define ERR_NOSUCHSERVER(client, servername) (":localhost 402 " + client + " " + servername + " :No such server\r\n")
#define ERR_NOMOTD(client) (":localhost 422 " + client + " :MOTD File is missing\r\n")
#define RPL_MOTDSTART(client, servername) (":localhost 375 " + client + " :- " + servername + " Message of the day - \r\n")
#define RPL_MOTD(client, motd_line) (":localhost 372 " + client + " :" + motd_line + "\r\n")
#define RPL_ENDOFMOTD(client) (":localhost 376 " + client + " :End of /MOTD command.\r\n")


// NAMES
# define RPL_NAMREPLY(client, symbol, channel, list_of_nicks) (":localhost 353 " + client + " " + symbol + " #" + channel + " :" + list_of_nicks + "\r\n")
# define RPL_ENDOFNAMES(client, channel) (":localhost 366 " + client + " #" + channel + " :End of /NAMES list.\r\n")

// NICK
# define ERR_NONICKNAMEGIVEN(client) (":localhost 431 " + client + " :There is no nickname.\r\n")
# define ERR_ERRONEUSNICKNAME(client, nickname) (":localhost 432 " + client + " " + nickname + " :Erroneus nickname\r\n")
# define ERR_NICKNAMEINUSE(client, nickname) (":localhost 433 " + client + " " + nickname + " :Nickname is already in use.\r\n")
# define RPL_NICK(oclient, uclient, client) (":" + oclient + "!" + uclient + "@localhost NICK " +  client + "\r\n")

// NOTICE
# define RPL_NOTICE(nick, username, target, message) (":" + nick + "!" + username + "@localhost NOTICE " + target + " " + message + "\r\n")

// OPER
# define ERR_NOOPERHOST(client) ("491 " + client + " :No O-lines for your host\r\n")
# define RPL_YOUREOPER(client) ("381 " + client + " :You are now an IRC operator\r\n")

// PART
# define RPL_PART(user_id, channel, reason) (user_id + " PART #" + channel + " " + (reason.empty() ? "." : reason ) + "\r\n")

// PASS
# define ERR_PASSWDMISMATCH(client) (":localhost 464 " + client + " :Password incorrect.\r\n")

// PING
# define RPL_PONG(user_id, token) (user_id + " PONG " + token + "\r\n")

// QUIT
# define RPL_QUIT(user_id, reason) (user_id + " QUIT :Quit: " + reason + "\r\n")
# define RPL_ERROR(user_id, reason) (user_id + " ERROR :" + reason + "\r\n")

// PRIVMSG
# define ERR_NOSUCHNICK(client, target) ("401 " + client + " " + target + " :No such nick/channel\r\n")
# define ERR_NORECIPIENT(client) ("411 " + client + " :No recipient given PRIVMSG\r\n")
# define ERR_NOTEXTTOSEND(client) ("412 " + client + " :No text to send\r\n")
# define RPL_PRIVMSG(nick, username, target, message) (":" + nick + "!" + username + "@localhost PRIVMSG " + target + " " + message + "\r\n")

// TOPIC
# define RPL_TOPIC(client, channel, topic) (":localhost 332 " + client + " #" + channel + " " + topic + "\r\n")
# define RPL_NOTOPIC(client, channel) (":localhost 331 " + client + " #" + channel + " :No topic is set\r\n")

// USER
# define ERR_ALREADYREGISTERED(client) (":localhost 462 " + client + " :You may not reregister.\r\n")







#endif

#include <csignal>

extern bool	server_shutdown;

struct server_op
{
	std::string name;
	std::string	host;
	std::string	password;
};

class Server
{
	private:
		struct addrinfo					_hints;
		struct addrinfo					*_servinfo;
		int								_server_socket_fd;
		std::map<const int, Client>		_clients;
		std::map<std::string, Channel>	_channels;
		std::string						_port;
		std::string						_password;
		std::string						_datetime;
		std::vector<server_op>			_irc_operators;
		std::string						_motd;
	
	public:
		// Constructor & destructor
		Server(std::string port, std::string password, struct tm *timeinfo);
		Server();
		~Server();
		// Accessors
		void								setHints();
		std::string							getPort() const;
		std::string							getPassword() const;
		void								setPassword(std::string new_pwd);
		std::string							getDatetime() const;
		void								setDatetime(struct tm *timeinfo);
		std::map<std::string, Channel>& 	getChannels();
		std::map<const int, Client>&		getClients();
		std::vector<server_op>&				getIrcOperators();
		std::string							getMotd() const;
		void								setMotd(std::string buffer);
		
		// Running Server functions
		int 		readFromConfigFile(char *filename);
		int			fillServinfo(char *port);
		int			launchServer();
		int			manageServerLoop();
		int			createClientConnexion(std::vector<pollfd>& poll_fds, std::vector<pollfd>& new_pollfds);
		int			handleExistingConnexion(std::vector<pollfd>& poll_fds, std::vector<pollfd>::iterator &it);
		int			handlePolloutEvent(std::vector<pollfd>& poll_fds, std::vector<pollfd>::iterator &it, const int current_fd);
		int			handlePollerEvent(std::vector<pollfd>& poll_fds, std::vector<pollfd>::iterator &it);
		// Manage Clients functions
		void		addClient(int client_socket, std::vector<pollfd> &poll_fds);
		// void 		delClient(std::vector<pollfd> &poll_fds, int current_fd);
		void 		delClient(std::vector<pollfd> &poll_fds, std::vector<pollfd>::iterator &it, int current_fd);
		void 		fillClients(std::map<const int, Client> &client_list, int client_fd, std::string cmd);
		// Parsing & Commands functions
		void		parseMessage(const int client_fd, std::string message);
		void		execCommand(int const client_fd, std::string cmd_line);
		// Display functions
		void		printChannel(std::string &channelName);
		void		printOper(std::string &channelName);
		// Custom exceptions
		class InvalidClientException : public std::exception {
			public :
					const char *	what (void) const throw();
		};
		// Channel functions
		void	addChannel(std::string &channelName);
		void	addClientToChannel(std::string &channelName, Client &client);
		bool	isChannel(std::string &channelName);
};

#endif

bool server_shutdown = false;

static void	signal_handler(int signal)
{
	(void)signal;
	server_shutdown = true;
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		time_t rawtime;
		struct tm * timeinfo;

		time (&rawtime);
		timeinfo = localtime(&rawtime);

		signal(SIGINT, signal_handler);
		Server server(argv[1], argv[2], timeinfo);

		char filename[39] = "srcs/config/ManageServOperators.config";
		server.readFromConfigFile(filename);
		
		// The three following functions calls are just set up
		server.setHints();
		if (server.fillServinfo(argv[1]) == FAILURE)
			return (FAILURE);
		server.launchServer();
		// Below, the main loop for server/client connection
		try
		{
			server.manageServerLoop();
		}
		catch(const std::exception& e) 
		{
			std::cerr << RED << "Caught exception : " << RESET << e.what() << std::endl;
		}

		return (SUCCESS);
	}
	else
	{
		std::cout << "Correct usage is ./ircserv [port] [password] :)" << std::endl;
		return (FAILURE);
	}
}

### _ :floppy_disk: Subject requirements


**1.** Code the IRC server in C++98
**2.** Your binary should look like this : `./ircserv <port> <password>`
**3.** You should use `poll()` and only **once**.
**4.** The client/server communication will be TCP/IP (v4 or v6)
**5.** The following features are mandatory :
> **i)** You should be able to register, i.e to define a nickname, a username

> **ii)** You should be able to join a channel, send or receive private messages

> **iii)** Every message sent by a client in a channel must be received by all of the clients who have joined this channel

> **iv)** You should have normal users and operators, and implement the operators' specific commands
**6.** No leaks (even still reachables) and handle the signals (partial messages with `CTRL+D`, suspended process with `CTRL+Z`, and obviously SIGINT (`CTRL+C`))
**7.** (bonuses) implement a bot + file transfer.


___
### :high_brightness: Commands that we implemented :



| Command | Description |
| :-----------: | :----------- |
| Invite | The `INVITE` command is used to invite a user to a channel. |
| Join | The `JOIN` command indicates that the client wants to join the given channel(s), each channel using the given key for it. |
| Kick | The `KICK` command can be used to request the forced removal of a user from a channel. |
| Kill | The `KILL` command is used to close the connection between a given client and the server they are connected to. `KILL` is a privileged command and is available only to IRC Operators. |
| List | The `LIST` command is used to get a list of channels along with some information about each channel. |
| Mode | The `MODE` command is used to set or remove options (or modes) from a given target. Our user modes : i, o. Our channels modes: b,k,m,o,p,s,t,v |
| Motd | The `MOTD` command is used to get the “Message of the Day” of the given server. |
| Names | The `NAMES` command is used to view the nicknames joined to a channel and their channel membership prefixes. |
| Nick | The `NICK` command is used to give the client a nickname or change the previous one. |
| Notice | The `NOTICE` command is used to send notices between users, as well as to send notices to channels. The difference between `NOTICE` and `PRIVMSG` is that automatic replies must never be sent in response to a `NOTICE` message.  |
| Oper | The `OPER` command is used by a normal user to obtain IRC operator privileges.  |
| Part | The `PART` command removes the client from the given channel(s). |
| Pass | The `PASS` command is used to set a ‘connection password’. If set, the password must be set before any attempt to register the connection is made. |
| Ping | The `PING` command is sent by either clients or servers to check the other side of the connection is still connected and/or to check for connection latency, at the application layer. |
| Privmsg | The `PRIVMSG` command is used to send private messages between users, as well as to send messages to channels. |
| Quit | The `QUIT` command is used to terminate a client’s connection to the server. The server acknowledges this by replying with an `ERROR` message and closing the connection to the client. |
| Topic | The `TOPIC` command is used to change or view the topic of the given channel. |
| User | The `USER` command is used at the beginning of a connection to specify the username and realname of a new user. |
>>>>>>> 37a2fdd9bf087d2d05d3537917363c1c3ffb6086
