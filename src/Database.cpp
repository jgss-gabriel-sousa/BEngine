#include "Database.h"

Database::Database(){
    availableToLoading = true;
}

bool Database::addPlayerFromFile(std::string fileLine){
    LogPush("Database::addPlayerFromFile");
    availableToLoading = false;

    std::string name, auxString, faceIconFilePath, nationality, lane;
    int age, skill, experience,fanBase;
    int aux;


    if(fileLine.size() == 0){
        return false;
    }
    if((fileLine.find("#") != std::string::npos)){
        return false;
    }

    LogPush("Loading Player: ");

    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        name = fileLine.substr(0,aux);
        LogPush("Name: "+name);
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        auxString = fileLine.substr(0,aux);
        if(auxString == ""){
            age = 25;
            LogPush("Age: INVALID (Using Default value of 25");
        }else{
            age = std::stoi(auxString);
            LogPush("Age: "+auxString);
        }
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        nationality = fileLine.substr(0,aux);
        LogPush("Nationality: "+nationality);
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        lane = fileLine.substr(0,aux);
        LogPush("Lane: "+lane);
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        auxString = fileLine.substr(0,aux);
        skill = std::stoi(auxString);
        LogPush("Skill: "+auxString);
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        auxString = fileLine.substr(0,aux);
        experience = std::stoi(auxString);
        LogPush("Experience: "+auxString);
        fileLine = fileLine.substr(aux+1);
    }
    if((fileLine.find(";") != std::string::npos)){
        aux = fileLine.find(";");
        auxString = fileLine.substr(0,aux);
        fanBase = std::stoi(auxString);
        LogPush("Fan Base: "+auxString);
        fileLine = fileLine.substr(aux+1);
    }

    Player p(name,nationality,lane,age,skill,experience,fanBase);
    LogPush("------------------");
    this->_players[name] = p;

    return true;
}

void Database::addTeamFromFile(std::string filePath){
    LogPush("Database::addTeamFromFile");

    std::string auxString, fileLine;
    std::string teamName, country;
    int aux, line = 0, actualScope = 0;
    float teamCash;
    std::vector<std::string> coachStaff;
    std::vector<std::string> playersActive;
    std::vector<std::string> playersSubstitute;
    std::vector<std::string> playersLoaned;
    std::vector<std::string> playersInLoan;
    std::vector<std::string> playersInactive;
    std::ifstream file;
    std::ofstream fileTeamTemp;
    bool isNewTeam = true;
    bool isEndOfTeam = false;

    file.open(filePath,std::ios::in);
    fileTeamTemp.open("data/teamsTemp.txt");

    if(file.is_open()){
        while(!file.eof() && !file.bad()){
            getline(file,fileLine);
            line++;

            // Defining the scopes
            if(fileLine.find("<<") != std::string::npos)
                actualScope = teamScope::commentary;
            if(fileLine.find("#") != std::string::npos)
                continue;
            if(fileLine.find(">>") != std::string::npos){
                actualScope = teamScope::nothing;
                aux = fileLine.find(">>");
                fileLine = fileLine.substr(aux+2);
            }

            //If is a commentary just get out
            if(actualScope == teamScope::commentary)
                continue;

            if(fileLine.find("(") != std::string::npos)
                actualScope = teamScope::team;
            if(fileLine.find("{") != std::string::npos){
                isNewTeam = true;
            }
            if(fileLine.find("coach:") != std::string::npos){
                actualScope = teamScope::coach;
                continue;
            }
            if(fileLine.find("active:") != std::string::npos){
                actualScope = teamScope::active;
                continue;
            }
            if(fileLine.find("substitute:") != std::string::npos){
                actualScope = teamScope::substitute;
                continue;
            }
            if(fileLine.find("loaned:") != std::string::npos){
                actualScope = teamScope::loaned;
                continue;
            }
            if(fileLine.find("in loan:") != std::string::npos){
                actualScope = teamScope::inLoan;
                continue;
            }
            if(fileLine.find("inactive:") != std::string::npos){
                actualScope = teamScope::inactive;
                continue;
            }
            if(fileLine.find("}") != std::string::npos){
                isEndOfTeam = true;
                actualScope = teamScope::team;
            }
            if(fileLine.size() == 0){
                continue;
            }


            //Processing string with scope info

            if(isNewTeam){
                while(playersActive.size() > 0){
                    LogPush("Active: "+playersActive.at(playersActive.size()-1));
                    playersActive.pop_back();
                }
                while(playersSubstitute.size() > 0){
                    LogPush("Substitute: "+playersSubstitute.at(playersSubstitute.size()-1));
                    playersSubstitute.pop_back();
                }
                while(playersLoaned.size() > 0){
                    LogPush("Loaned: "+playersLoaned.at(playersLoaned.size()-1));
                    playersLoaned.pop_back();
                }
                while(playersInLoan.size() > 0){
                    LogPush("In Loan: "+playersInLoan.at(playersInLoan.size()-1));
                    playersInLoan.pop_back();
                }
                while(playersInactive.size() > 0){
                    LogPush("Inactive: "+playersInactive.at(playersInactive.size()-1));
                    playersInactive.pop_back();
                }
                isNewTeam = false;
            }

            if(actualScope == teamScope::nothing){
                continue;
            }
            if(actualScope == teamScope::team && isEndOfTeam == false){
                aux = fileLine.find("(");
                teamName = fileLine.substr(0,aux);
                LogPush("Team Name: "+teamName);
                fileLine = fileLine.substr(aux+1);

                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                LogPush("Cash: "+auxString);
                teamCash = std::stod(auxString);
                fileLine = fileLine.substr(aux+1);

                aux = fileLine.find(")");
                country = fileLine.substr(0,aux);
                LogPush("Country: "+country);
                continue;
            }
            if(actualScope == teamScope::coach && fileLine.find(";") != std::string::npos){
                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                coachStaff.push_back(auxString);
            }
            if(actualScope == teamScope::active && fileLine.find(";") != std::string::npos){
                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                playersActive.push_back(auxString);
            }
            if(actualScope == teamScope::substitute && fileLine.find(";") != std::string::npos){
                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                playersSubstitute.push_back(auxString);
            }
            if(actualScope == teamScope::inLoan && fileLine.find(";") != std::string::npos){
                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                playersInLoan.push_back(auxString);
            }
            if(actualScope == teamScope::inactive && fileLine.find(";") != std::string::npos){
                aux = fileLine.find(";");
                auxString = fileLine.substr(0,aux);
                playersInactive.push_back(auxString);
            }
            if(isEndOfTeam){
                Team t(teamName,country,teamCash);
                std::string aux;

                while(coachStaff.size() > 0){
                    aux = coachStaff[coachStaff.size()-1];
                    t.addPlayer(_players[aux],"coach");
                    coachStaff.pop_back();
                }
                while(playersActive.size() > 0){
                    aux = playersActive[playersActive.size()-1];
                    t.addPlayer(_players[aux],"active");
                    playersActive.pop_back();
                }
                while(playersSubstitute.size() > 0){
                    aux = playersSubstitute[playersSubstitute.size()-1];
                    t.addPlayer(_players[aux],"substitute");
                    playersSubstitute.pop_back();
                }
                while(playersLoaned.size() > 0){
                    aux = playersLoaned[playersLoaned.size()-1];
                    t.addPlayer(_players[aux],"loaned");
                    playersLoaned.pop_back();
                }
                while(playersInLoan.size() > 0){
                    aux = playersInLoan[playersInLoan.size()-1];
                    t.addPlayer(_players[aux],"in loan");
                    playersInLoan.pop_back();
                }
                while(playersInactive.size() > 0){
                    aux = playersInactive[playersInactive.size()-1];
                    t.addPlayer(_players[aux],"inactive");
                    playersInactive.pop_back();
                }

                this->_teams[teamName] = t;
                _teamsStrings.push_back(teamName);
                fileTeamTemp<<teamName<<std::endl;
                isEndOfTeam = false;
            }
        }
    }else{
        LogPush("\"data/teams.txt\" not found");
    }
}

void Database::addLeagueFromFile(std::string filePath){
    LogPush("Database::addLeagueFromFile");
    std::string auxString, fileLine, teamsString;
    std::string name, region, tier, format;
    bool franchise, twoSplits;
    std::vector<std::string> teams;
    int pos;
    bool commentary = false;
    std::ifstream file;

    file.open(filePath,std::ios::in);

    if(file.is_open()){
        while(!file.eof() && !file.bad()){
            getline(file,fileLine);

            // Commentaries
            if(fileLine.find("<<") != std::string::npos){
                commentary = true;
            }
            if(fileLine.find("#") != std::string::npos){
                continue;
            }
            if(fileLine.size() == 0){
                continue;
            }
            if(fileLine.find(">>") != std::string::npos){
                commentary = false;
                continue;
            }
            if(commentary == true){
                continue;
            }

            pos = fileLine.find("(");
            teamsString = fileLine.substr(pos);
            fileLine = fileLine.substr(0,pos);

            remove_if(fileLine.begin(), fileLine.end(), isspace);

            pos = fileLine.find(";");
            name = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);

            pos = fileLine.find(";");
            region = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);

            pos = fileLine.find(";");
            auxString = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);
            std::for_each(auxString.begin(), auxString.end(), [](char & c){
                c = ::tolower(c);
            });
            if(auxString == "true"){
                franchise = true;
            }else{
                franchise = false;
            }

            pos = fileLine.find(";");
            auxString = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);
            std::for_each(auxString.begin(), auxString.end(), [](char & c){
                c = ::tolower(c);
            });
            if(auxString == "true"){
                twoSplits = true;
            }else{
                twoSplits = false;
            }

            pos = fileLine.find(";");
            tier = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);

            pos = fileLine.find(";");
            format = fileLine.substr(0,pos);
            fileLine = fileLine.substr(pos+1);

            League l(name,region,franchise,twoSplits,tier,format);

            pos = teamsString.find(")");
            teamsString = teamsString.substr(1,pos-1);
            while(teamsString.find(",") != std::string::npos){
                pos = teamsString.find(",");
                auxString = teamsString.substr(0,pos);
                teamsString = teamsString.substr(pos+1);
                l.addTeam(auxString);
                setLeagueOfTeam(auxString,name);
                LogPush(auxString+" added to "+name);
            }
            l.addTeam(teamsString);
            setLeagueOfTeam(teamsString,name);
            LogPush(teamsString+" added to "+name);

            LogPush(name+"|"+region+"|"+tier+"|"+format);
            LogPush("----------------------------------");
            _leagues[name] = l;
            _leaguesStrings.push_back(name);
        }
    }else{
        LogPush("\"data/leagues.txt\" not found");
    }
}

void Database::resetDatabase(){
    LogPush("Database::resetDatabase");
    _players.clear();
    _teams.clear();
    _leagues.clear();
    _countries.clear();
    _teamsStrings.clear();
    _leaguesStrings.clear();
    _countryStrings.clear();
    availableToLoading = true;
}

void Database::playerTransfer(std::string player,std::string teamOrigin,std::string teamDestiny,float value){
    LogPush("Database::playerTransfer");
}

void Database::addPlayerToTeam(std::string player,std::string type,std::string team){
    LogPush("Database::addPlayerToTeam");
    Team t;
    Player p;

    t = _teams.at(team);
    p = _players.at(player);

    t.addPlayer(p,type);
}

Team Database::getTeam(std::string name){
    LogPush("Database::getTeam");
    return _teams[name];
}

void Database::addCountry(std::string country){
    LogPush("Database::addCountry = "+country);
    _countryStrings.push_back(country);
}

void Database::addCountryTag(std::string tag,std::string country){
    LogPush("Database::addCountryTag = "+tag+" = "+country);
    _countries[tag] = country;
}

void Database::setCountryOfTeams(){
    LogPush("Database::setCountryOfTeams");

    Team t;

    for(int i = 0; i < _teamsStrings.size(); i++){
        t = _teams[_teamsStrings[i]];
        t.setCountry(_countries[t.getCountry()]);
        _teams[_teamsStrings[i]] = t;
    }
}

void Database::setLeagueOfTeam(std::string team, std::string league){
    LogPush("Database::setLeagueOfTeam");

    Team t;

    t = _teams[team];
    t.setLeague(league);
    _teams[team] = t;
}

std::string Database::getCountry(int i){
    LogPush("Database::getCountry");
    return _countryStrings[i%_countryStrings.size()];
}

std::string Database::getCountryByTeam(std::string team){
    LogPush("Database::getCountryByTeam");
    Team t;

    t = _teams.at(team);

    return t.getCountry();
}

std::string Database::getLeague(int i){
    LogPush("Database::getLeague");
    return _leaguesStrings[i%_leaguesStrings.size()];
}

std::vector<std::string> Database::getPlayerNames(){
    LogPush("Database::getPlayerNames");
    std::vector<std::string> vectorOfNames;
    Player p;

    for(auto it=_players.begin(); it!=_players.end(); ++it){
        p = _players.at((*it).first);
        vectorOfNames.push_back(p.getName());
    }
    return vectorOfNames;
}

std::string Database::getLeaguesToLoading(int i){
    LogPush("Database::getLeaguesToLoading");

    if(i >= _leaguesStrings.size() || i < 0){
        return "end";
    }else{
        return _leaguesStrings[i];
    }
}

std::vector<std::string> Database::getTeamsinLeague(std::string league){
    LogPush("Database::getTeamsinLeague ("+league+")");
    std::vector<std::string> vectorOfTeams;
    Team t;

    for(int i = 0; i < _teamsStrings.size(); i++){
        t = _teams[_teamsStrings[i]];
        if(t.getLeague() == league){
            vectorOfTeams.push_back(t.getName());
        }
    }

    return vectorOfTeams;
}

Player Database::getPlayerByName(std::string name){
    Player p = _players[name];
    return p;
}













