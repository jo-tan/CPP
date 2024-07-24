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


#include "Irc.hpp"
#include "Server.hpp"
#include "Commands.hpp"

void	addToClientBuffer(Server *server, int const client_fd, std::string reply)
{
	Client &client = retrieveClient(server, client_fd);

	client.setSendBuffer(reply);
}

void	sendServerRpl(int const client_fd, std::string client_buffer)
{
	std::istringstream	buf(client_buffer);
	std::string			reply;
	
	send(client_fd, client_buffer.c_str(), client_buffer.size(), 0);
	while (getline(buf, reply))
	{
		std::cout << "[Server] Message sent to client " \
				  << client_fd << "       >> " << CYAN << reply << RESET << std::endl;
	}
}

Client&	retrieveClient(Server *server, int const client_fd)
{
	std::map<const int, Client>&		client_list = server->getClients();
	std::map<const int, Client>::iterator it_client = client_list.find(client_fd);
	
	Client &client = it_client->second;
	return (client);
}

Client*	getClient(Server *server, int const client_fd)
{
	std::map<const int, Client>&		client_list = server->getClients();
	std::map<const int, Client>::iterator it_client = client_list.find(client_fd);
	
	if (it_client == client_list.end())
		return (NULL);
	return (&it_client->second);
}

std::string	getListOfMembers(std::string client, Channel &channel)
{
	std::map<std::string, Client>&			client_list	= channel.getClientList();
	std::map<std::string, Client>::iterator	it;
	std::string								nick;
	std::string								members_list;

	for (it = client_list.begin(); it != client_list.end(); it++)
	{
		nick.clear();
		nick = it->second.getNickname();
		if (it->second.getMode().find('i') != std::string::npos\
			&& channel.doesClientExist(client) == false)
				continue;
			
		if (channel.isOperator(nick) == true)
			members_list += "@";
		members_list += nick;
		members_list += " ";
	}
	if (members_list.size() >= 1 && members_list[members_list.size() - 1] == ' ')
		members_list.erase(members_list.end()-1);
	return (members_list);
}

std::string	getChannelName(std::string msg_to_parse)
{
	std::string channel_name;
	size_t i = 0;
	while (msg_to_parse[i] && (!isalpha(msg_to_parse[i]) && !isdigit(msg_to_parse[i]) && msg_to_parse[i] != '-' && msg_to_parse[i] != '_'))
		i++;
	while (msg_to_parse[i] && (isalpha(msg_to_parse[i]) || msg_to_parse[i] == '-' || msg_to_parse[i] == '_' || isdigit(msg_to_parse[i])))
		channel_name += msg_to_parse[i++];
	return (channel_name);
}

std::string	getSymbol(Channel &channel)
{
	std::string symbol;

	if (channel.getMode().find('s') != std::string::npos) {
		symbol += "@";
	} else if (channel.getMode().find('p') != std::string::npos) {
		symbol += "*";
	} else {
		symbol += "=";
	}
	return (symbol); 
}

void	sendClientRegistration(Server *server, int const client_fd, std::map<const int, Client>::iterator &it)
{
	addToClientBuffer(server, client_fd, RPL_WELCOME(user_id(it->second.getNickname(), it->second.getUsername()), it->second.getNickname()));
	addToClientBuffer(server, client_fd, RPL_YOURHOST(it->second.getNickname(), "42_Ftirc", "1.1"));
	addToClientBuffer(server, client_fd, RPL_CREATED(it->second.getNickname(), server->getDatetime()));
	addToClientBuffer(server, client_fd, RPL_MYINFO(it->second.getNickname(), "localhost", "1.1", "io", "kost", "k"));
	addToClientBuffer(server, client_fd, RPL_ISUPPORT(it->second.getNickname(), "CHANNELLEN=32 NICKLEN=9 TOPICLEN=307"));
	
	std::ifstream		data;
	char				filepath[24] = "srcs/config/motd.config";

	data.open(filepath);
	if (!data)
	{
		addToClientBuffer(server, client_fd, ERR_NOMOTD(it->second.getNickname()));
		return ;
	}
	else
	{
		std::string		motd_lines;
		std::string		buf;
		
		buf = RPL_MOTDSTART(it->second.getNickname(), "42_Ftirc (localhost)");
		while (getline(data, motd_lines))
		{
			buf += RPL_MOTD(it->second.getNickname(), motd_lines);
		}
		buf += RPL_ENDOFMOTD(it->second.getNickname());
		addToClientBuffer(server, client_fd, buf);
	}
	data.close();
}

*  Numeric Replies:
 *  
 *  ERR_NEEDMOREPARAMS (461)
 *  ERR_NOSUCHCHANNEL (403)
 *  ERR_TOOMANYCHANNELS (405)
 *  ERR_BADCHANNELKEY (475)
 *  ERR_BANNEDFROMCHAN (474)
 *  ERR_CHANNELISFULL (471)
 *  ERR_INVITEONLYCHAN (473)
 *  ERR_BADCHANMASK (476)
 *  RPL_TOPIC (332)
 *  RPL_TOPICWHOTIME (333)
 *  RPL_NAMREPLY (353)
 *  RPL_ENDOFNAMES (366)
 *  
 *  Examples:
 * 	[CLIENT]  JOIN #foobar
 *  [SERVER] ; join channel #foobar.
 * 
 * 	[CLIENT]  JOIN #foo,#bar fubar,foobar
 * 	[SERVER]; join channel #foo using key "fubar" and channel #bar using key "foobar".
 */

The KICK command can be used to request the forced removal of a user 
 *  from a channel. It causes the <user> to be removed from the <channel> by force. 
 *  If no comment is given, the server SHOULD use a default message instead.
 * 
 *  Parameters: <channel> <user> *( "," <user> ) [<comment>]
 * 
 * Numeric Replies:
 * 
 * ERR_NEEDMOREPARAMS (461)
 * ERR_NOSUCHCHANNEL (403)
 * ERR_CHANOPRIVSNEEDED (482)
 * ERR_USERNOTINCHANNEL (441)
 * ERR_NOTONCHANNEL (442)
 * 
 * Example:
 * Client's request : KICK #Finnish John :Speaking English
 * 
 * Server's Response: " Command to kick John from #Finnish using "Speaking English" 
 * 						as the reason (comment)."
 *
 * @param server
 * @param cmd_infos Structure w/ prefix, command name and message
 * 
 * If the exact name of a channel is given, the only information about 
 * 		this channel is requested; otherwise, a list of all channels will be 
 * 		displayed.
 * 
 * 	Syntax : 
 * 	[IRSSI] LIST [-yes] [<channel>]
 * 	
 * 	Numeric Replies:
 * 		RPL_LISTSTART (321) : marks the start of a channel list. 
 * 		RPL_LIST (322) : sends information about a channel to the client.
 * 		RPL_LISTEND (323) : indicates the end of a LIST response.
 * 
 * 	Examples:
 * 		/LIST
 * 		/LIST -yes => "LIST" when received by server
 * 		/LIST #ubuntu
 * 
 * The MODE command is used to set or remove options (or modes) from a given target.
 * 
 * Parameters: <target> [<modestring> [<mode arguments>...]]
 * 
 * <modestring> starts with a plus ('+', 0x2B) or minus ('-', 0x2D) character, and is made up of the following characters:
 * '+': Adds the following mode(s).
 * '-': Removes the following mode(s).
 * 'a-zA-Z': Mode letters, indicating which modes are to be added/removed.
 * 
 * User case :
 * If <modestring> is given, the supplied modes will be applied : a MODE message will be sent to the user containing the changed modes. 
 * If one or more modes sent are not implemented on the server, 
 * the server MUST apply the modes that are implemented, and then send the ERR_UMODEUNKNOWNFLAG (501) in reply along with the MODE message.
 * 
 * Channel case :
 * syntax command : /mode <channel> <+ ou -> <mode> [parametres]
 * If the user has permission to change modes on the target, the supplied modes will be applied based on the type of the mode (see below). 
 * For type A, B, and C modes, arguments will be sequentially obtained from <mode arguments>. 
 * - If a type B or C mode does not have a parameter when being set, the server MUST ignore that mode. 
 * - If a type A mode has been sent without an argument : 
 * the contents of the list MUST be sent to the user, 
 * unless it contains sensitive information the user is not allowed to access. 
 * When the server is done processing the modes, a MODE command is sent to all members of the channel containing the mode changes. 
 * Servers MAY choose to hide sensitive information when sending the mode changes.
 * 
 * Exemples :
 * - +o : /mode #cool +o MEAT (MEAT devient opérateur sur #cool)
 * Message à send aux users du channel : ':irc.example.com MODE #cool +o MEAT'; 
 * The irc.example.com server gave channel operator privileges to MEAT on #cool.
 * - +k : /mode #cool +k COOLKEY (protège le channel par le mot de passe COOLKEY)
 * - +s : /mode #cool +s (le channel devient secret)
 * - plusieur modes : /mode #cool +ts (le channel est en mode +t +s)
 * 
 * @param server
 * @param client_fd User sending a msg
 * @param cmd_infos Structure w/ prefix, command name and message
 * 
 * Useful link : https://modern.ircdocs.horse/#mode-message
 * https://www.techbull.com/techbull/guide/internet/irccommande.html

The MOTD command is used to get the “Message of the Day” of the given 
 * server. If <target> is not given, the MOTD of the server the client is 
 * connected to should be returned.
 * 
 *  Syntax : MOTD [<target>]
 * 
 *  If the MOTD can be found, one RPL_MOTDSTART numeric is returned, followed by
 *  one or more RPL_MOTD numeric, then one RPL_ENDOFMOTD numeric.
 * 
 * 	If the MOTD does not exist or could not be found, the ERR_NOMOTD numeric is returned.
 * 
 *  Numeric replies:
 *   ERR_NOSUCHSERVER (402)
 *   ERR_NOMOTD (422)
 *   RPL_MOTDSTART (375)
 *   RPL_MOTD (372)
 *   RPL_ENDOFMOTD (376)

 * The NAMES command is used to view the nicknames joined to a channel.
 *  If the channel name is invalid or the channel does not exist, one RPL_ENDOFNAMES 
 * 	numeric containing the given channel name should be returned.
 * 
 * 	Syntax: NAMES <channel>{,<channel>}
 * 	
 * 	Numeric Replies:
 * 	
 * 	RPL_NAMREPLY (353)
 * 	RPL_ENDOFNAMES (366)
 * 
 * 	Examples:
 * 	[CLIENT] /NAMES #test,#42
 * 	[SERVER] <client> <symbol> #test :<nick1> <nick2>


The NICK command is used to give the client a nickname or 
 * 		change the previous one.
 * 
 * 	Syntax: NICK <nickname>
 * 
 * 	Nicknames are non-empty strings with the following restrictions:
 * 	
 * 	They MUST NOT contain any of the following characters: 
 * 	- space (' '), 
 * 	- comma (','), 
 * 	- asterisk ('*'), 
 * 	- question mark ('?'), 
 * 	- exclamation mark ('!'), 
 * 	- at sign ('@'),
 * 	- dot ('.').
 * 	
 * 	They MUST NOT start with any of the following characters: 
 * 	dollar ('$'), colon (':'), diese (#).
 * 	
 * 	Numeric Replies:
 * 
 * 	ERR_NONICKNAMEGIVEN (431)
 * 	ERR_ERRONEUSNICKNAME (432)
 * 	ERR_NICKNAMEINUSE (433)
 * 	ERR_NICKCOLLISION (436)
 * 
 * 	Example:
 * 	[CLIENT] /Nick mike


The NOTICE command is used to send notices between users, as well as to send notices to channels. 
 * <target> is interpreted the same way as it is for the PRIVMSG command.
 * 
 * The NOTICE message is used similarly to PRIVMSG. 
 * The difference between NOTICE and PRIVMSG is that automatic replies must never be sent in response to a NOTICE message. 
 * This rule also applies to servers – they must not send any error back to the client on receipt of a NOTICE command. 

   @param server
   @param client_fd User sending a msg
   @param cmd_infos Structure w/ prefix, command name and message

   Useful link : https://modern.ircdocs.horse/#notice-message


 The OPER command is used by a normal user to obtain IRC operator privileges.
 * 	Both parameters are required for the command to be successful.
 *
 *  Command: OPER
 *  Parameters: <name> <password>
 *
 * Numeric Replies:
 *
 * ERR_NEEDMOREPARAMS (461)
 * ERR_PASSWDMISMATCH (464)
 * ERR_NOOPERHOST (491)
 * RPL_YOUREOPER (381)
 *
 * Example:
 *  [CLIENT] OPER foo bar
 *  [SERVER] ; Attempt to register as an operator using a name of "foo" and the password "bar".


The PART command removes the client from the given channel(s).
 * 
 * 	Syntax: PART <channel>{,<channel>} [<reason>]
 * 
 *  On sending a successful PART command, the user will receive a PART message 
 *  from the server for each channel they have been removed from. 
 *  <reason> is the reason that the client has left the channel(s).
 * 
 *  Numeric Replies:
 *   ERR_NEEDMOREPARAMS (461)
 *   ERR_NOSUCHCHANNEL (403)
 *   ERR_NOTONCHANNEL (442)
 * 	
 * 	Example:
 * 	[IRSSI] /PART #test,#hey :Dining
 * 	[SERVER] leaves both channels #test and #hey with the reason "Dining"
 * 	[SERVER to CLIENT]"@user_id PART #channel Dining" (for EACH channel they leave)

The PASS command is used to set a ‘connection password’.
 * The password supplied must match the one defined in the server configuration.
 * 	
 * Syntax: PASS <password>
 * 
 * Numeric replies:
 * 	ERR_NEEDMOREPARAMS (461)
 * 	ERR_ALREADYREGISTERED (462)
 * 	ERR_PASSWDMISMATCH (464)
 * 
 * Example :
 *  [CLIENT] /PASS secretpassword



The PING command is sent to check the other side of the connection is still
 * 		connected, and/or to check for connection latency.
 * 
 * 		When receiving a PING message, clients or servers must reply to it with a
 * 		PONG message with the same <token> value. 
 * 
 * 		Numeric replies:
 * 		461 - ERR_NEEDMOREPARAMS -  "<client> <command> :Not enough parameters" > DEALT BY IRSSI
 * 		409 - ERR_NOORIGIN - "<client> :No origin specified" (when <token> is empty) > DEALT BY IRSSI
 * 
 * 		IRSSI :
 * 		With this reference client, sending a PING to a server sends a CTCP request
 * 		to a nickname or a channel. Using the char '*' pings every user in a channel.
 * 		Syntax : PING [<nick> | <channel> | *]
 * 
 * @return SUCCESS (0) or FAILURE (1) 

int	ping(Server *server, int const client_fd, cmd_struct &cmd)
{
	Client		&client		= retrieveClient(server, client_fd);
	std::string	nickname	= client.getNickname();
	std::string	username	= client.getUsername();

	if (cmd.message[0] == ' ')
		cmd.message.erase(0, 1);
	cmd.message.insert(0, ":");
	addToClientBuffer(server, client_fd, RPL_PONG(user_id(nickname, username), cmd.message));

	return (SUCCESS);
}

PRIVMSG is used to send private messages between users, as well as to
   send messages to channels.  <msgtarget> is usually the nickname of
   the recipient of the message, or a channel name.
   
   Parameters: <msgtarget> <text to be sent>

   The <msgtarget> parameter may also be a host mask (#<mask>) or server
   mask ($<mask>).  In both cases the server will only send the PRIVMSG
   to those who have a server or host matching the mask.  The mask MUST
   have at least 1 (one) "." in it and no wildcards following the last
   ".".  This requirement exists to prevent people sending messages to
   "#*" or "$*", which would broadcast to all users.  Wildcards are the
   '*' and '?'  characters.  This extension to the PRIVMSG command is
   only available to operators.

   Numeric Replies:
    ERR_NOSUCHNICK (401) -OK
    ERR_CANNOTSENDTOCHAN (404)
    ERR_TOOMANYTARGETS (407) 
    ERR_NORECIPIENT (411) -OK
    ERR_NOTEXTTOSEND (412) -OK
    ERR_NOTOPLEVEL (413)
    ERR_WILDTOPLEVEL (414)
    RPL_AWAY (301)

   @param server
   @param client_fd User sending a msg
   @param cmd_infos Structure w/ prefix, command name and message

   EXAMPLES :
   Examples:

   :Angel!wings@irc.org PRIVMSG Wiz :Are you receiving this message ?
    ; Message from Angel to Wiz.

   PRIVMSG Angel :yes I'm receiving it !
	; Command to send a message to Angel.

   PRIVMSG jto@tolsun.oulu.fi :Hello !
	; Command to send a message to a user on server tolsun.oulu.fi with
    username of "jto".

   PRIVMSG kalt%millennium.stealth.net@irc.stealth.net :Are you a frog?
   	; Message to a user on server irc.stealth.net with username of "kalt", 
	and connected from the host millennium.stealth.net.

   PRIVMSG kalt%millennium.stealth.net :Do you like cheese?
    ; Message to a user on the local server with username of "kalt", and
    connected from the host millennium.stealth.net.

   PRIVMSG Wiz!jto@tolsun.oulu.fi :Hello !
   	; Message to the user with nickname Wiz who is connected from the host
    tolsun.oulu.fi and has the username "jto".

   PRIVMSG $*.fi :Server tolsun.oulu.fi rebooting.
    ; Message to everyone on a server which has a name matching *.fi.

   PRIVMSG #*.edu :NSFNet is undergoing work, expect interruptions
    ; Message to all users who come from a host which has a name matching *.edu.

	useful link : https://irssi.org/documentation/help/msg/
   https://modern.ircdocs.horse/#errnosuchnick-401
   http://abcdrfc.free.fr/rfc-vf/rfc1459.html (errors)
   https://askubuntu.com/questions/855881/irssi-where-do-private-messages-go (how to use IRSSI)
   https://datatracker.ietf.org/doc/html/rfc2812#section-3.3 RFC DE REFERENCE
 

 static void	broadcastToChan(Server *server, Channel &channel, int const client_fd, std::string nick, std::string user, std::string reason);
static void	removeFromServer(Server *server, std::string killed_user);
/**
 * @brief The QUIT command is used to terminate a client’s connection to the server. 
 *  The server acknowledges this by replying with an ERROR message and closing 
 *  the connection to the client.
 * 
 * 	When connections are terminated by a client-sent QUIT command, 
 *  servers SHOULD prepend <reason> with the ASCII string "Quit: " when sending 
 *  QUIT messages to other clients, to represent that this user terminated the 
 *  connection themselves. This applies even if <reason> is empty, in which case 
 *  the reason sent to other clients SHOULD be just this "Quit: " string. 
 * 	
 *  Parameters: [<reason>]
 * 
 *  Example : [CLIENT] QUIT :Gone to have lunch   
 * 			  [SERV] ;Client exiting from the network
 * 
 * 	Source: https://modern.ircdocs.horse/#quit-message
 */
void		quit(Server *server, int const client_fd, cmd_struct cmd_infos)
{
	Client& 								  client   = retrieveClient(server, client_fd);
	std::string								  reason   = getReason(cmd_infos.message);
	std::map<std::string, Channel>&			  channels = server->getChannels();
	std::map<std::string, Channel>::iterator  chan	   = channels.begin();

	// inform the concerned user
	addToClientBuffer(server, client_fd, RPL_QUIT(user_id(client.getNickname(), client.getUsername()), reason));
	// inform all the users that share a channel w/ the user quitting
	for (; chan != channels.end(); chan++) // check all channels
	{
		std::map<std::string, Client>& 			chan_members = chan->second.getClientList();
		std::map<std::string, Client>::iterator	member		 = chan_members.begin();
		for (; member != chan_members.end(); member++) // check all chan_members
		{
			if (member->second.getClientFd() == client_fd) // erase user from the chan + inform the others 
			{
				chan_members.erase(client.getNickname());
				broadcastToChan(server, chan->second, client_fd, client.getNickname(), client.getUsername(), reason);
				break ;
			}
		}
	}
	// close the connection (no need for irssi, but nc needs it)
	client.setDeconnexionStatus(true);
	removeFromServer(server, client.getNickname());
}

static void	broadcastToChan(Server *server, Channel &channel, int const client_fd, std::string nick, std::string user, std::string reason)
{
	std::map<std::string, Client>::iterator member = channel.getClientList().begin();
	
	(void) client_fd;
	while (member != channel.getClientList().end())
	{
		if (member->second.getClientFd() != client_fd)
		{
			addToClientBuffer(server, member->second.getClientFd(), \
				RPL_QUIT(user_id(nick, user), reason));
		}
			
		member++;
	}
}

static void	removeFromServer(Server *server, std::string killed_user)
{
	std::map<std::string, Channel>&				channels = server->getChannels();
	std::map<std::string, Channel>::iterator	chan;
	for (chan = channels.begin(); chan != channels.end(); chan++)
	{
		if (chan->second.doesClientExist(killed_user))
		{
			chan->second.getClientList().erase(killed_user);
		}
	}
}

Command : TOPIC <channel> [<topic>]
 * 			
 * 	The TOPIC command is used to change or view the topic of the given channel. 
 * 	If <topic> is not given, either RPL_TOPIC or RPL_NOTOPIC is returned 
 * 	specifying the current channel topic or lack of one. 
 * 	If <topic> is an empty string, the topic for the channel will be cleared.
 * 
 * 	Numeric Replies:
 * 	
 * 	ERR_NEEDMOREPARAMS (461)
 * 	ERR_NOSUCHCHANNEL (403)
 * 	ERR_NOTONCHANNEL (442)
 * 	RPL_NOTOPIC (331)
 * 	RPL_TOPIC (332)
 * 	
 * 	Examples:
 * 	[CLIENT] TOPIC #test :New topic
 *  [SERVER] ; Setting the topic on "#test" to "New topic".
 * 
 * 	[CLIENT] TOPIC #test :
 * 	[SERVER] ; Clearing the topic on "#test"
 * 
 * 	[CLIENT] TOPIC #test
 * 	[SERVER] ; Checking the topic for "#test"
 
 The USER command is used at the beginning of a connection to specify 
 * 		  the username and realname of a new user.
 * 		
 * 	The minimum length of <username> is 1, ie. it MUST NOT be empty. 
 * 	If it is empty, the server SHOULD reject the command with ERR_NEEDMOREPARAMS.
 * 
 *  If a client tries to send the USER command after they have already completed
 *  registration with the server, the ERR_ALREADYREGISTERED reply should be sent
 *  and the attempt should fail.
 * 	
 *  SYNTAX : USER <username> 0 * <realname>
 * 
 * 	Numeric Replies:
 * 		ERR_NEEDMOREPARAMS (461)
 * 		ERR_ALREADYREGISTERED (462)
 * 
 *  Examples:
 * 	[Client] USER marine 0 * :Marine Sanjuan
 * 	=> Username is marine, Realname is Marine Sanjuan
 * 
 * 	[Client] USER msanjuan msanjuan localhost :Marine SANJUAN
 *  => Username is msanjuan, Realname is Marine Sanjuan
 