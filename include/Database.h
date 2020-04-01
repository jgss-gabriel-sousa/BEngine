#pragma once

#include "log.h"
#include "DEFINITIONS.h"
#include <vector>
#include <fstream>

#include "player.h"
#include "team.h"
#include "league.h"

enum teamScope{
    nothing,
    commentary,
    team,
    coach,
    active,
    substitute,
    loaned,
    inLoan,
    inactive
};

class Database{
public:
    Database();
    ~Database(){}

    bool addPlayerFromFile(std::string fileLine);
    void addTeamFromFile(std::string filePath);
    void addLeagueFromFile(std::string fileLine);

    void playerTransfer(std::string player,std::string origin,std::string destiny,float value);
    void addPlayerToTeam(std::string player,std::string type,std::string team);

    void resetDatabase();
    bool IsAvailableToLoading(){return availableToLoading;;}

    void addCountry(std::string country);
    void addCountryTag(std::string tag,std::string country);
    void setCountryOfTeams();
    void setLeagueOfTeam(std::string name,std::string league);
    std::string getLeaguesToLoading(int i);
    std::string getCountry(int i);
    std::string getCountryByTeam(std::string team);
    std::vector<std::string> getTeamsinLeague(std::string league);
    Team getTeam(std::string name);
    std::string getLeague(int i);
    std::vector<std::string> getPlayerNames();
    Player getPlayerByName(std::string name);

private:
    bool availableToLoading;

    std::map<std::string,Player> _players;
    std::map<std::string,Team> _teams;
    std::map<std::string,League> _leagues;
    std::map<std::string,std::string> _countries;
    std::vector<std::string> _teamsStrings;
    std::vector<std::string> _leaguesStrings;
    std::vector<std::string> _countryStrings;
};
