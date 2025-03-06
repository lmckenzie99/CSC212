#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct Dynasty {
    std::string player1;
    std::string player2;
    int streakLength;
    int index;
};

bool compareTeams(const Dynasty& team1, const Dynasty& team2) {
    return team1.index < team2.index;
}

int main() {
    int numPlayers;
    std::cin >> numPlayers;

    std::queue<std::string> playerQueue;
    std::vector<std::string> allPlayers;
    for (int i = 0; i < numPlayers; i++) {
        std::string playerName;
        std::cin >> playerName;
        playerQueue.push(playerName);
        allPlayers.push_back(playerName);
    }

    std::string results;
    std::cin >> results;

    std::string whitePlayer1, whitePlayer2, blackPlayer1, blackPlayer2;
    whitePlayer1 = playerQueue.front();
    playerQueue.pop();
    blackPlayer1 = playerQueue.front();
    playerQueue.pop();
    whitePlayer2 = playerQueue.front();
    playerQueue.pop();
    blackPlayer2 = playerQueue.front();
    playerQueue.pop();

    std::unordered_map<std::string, std::vector<int>> playerStreaks;
    for (const auto& player : allPlayers) {
        playerStreaks[player] = {0};
    }

    std::vector<Dynasty> winningTeams;
    char previousWinner = 'A';

    for (auto gameResult : results) {
        for (auto& player : allPlayers) {
            playerStreaks[player].push_back(0);
        }

        playerStreaks[whitePlayer1].pop_back();
        playerStreaks[whitePlayer2].pop_back();
        playerStreaks[blackPlayer1].pop_back();
        playerStreaks[blackPlayer2].pop_back();
        playerStreaks[whitePlayer1].push_back(playerStreaks[whitePlayer1].back() + 1);
        playerStreaks[whitePlayer2].push_back(playerStreaks[whitePlayer2].back() + 1);
        playerStreaks[blackPlayer1].push_back(playerStreaks[blackPlayer1].back() + 1);
        playerStreaks[blackPlayer2].push_back(playerStreaks[blackPlayer2].back() + 1);

        Dynasty winningTeam;
        if (gameResult == previousWinner) {
            winningTeam.streakLength = winningTeams[winningTeams.size() - 1].streakLength + 1;
        } else {
            winningTeam.streakLength = 1;
        }

        if (gameResult == 'W') {
            winningTeam.player1 = whitePlayer1;
            winningTeam.player2 = whitePlayer2;

            std::swap(whitePlayer1, whitePlayer2);
            playerQueue.push(blackPlayer2);
            blackPlayer2 = blackPlayer1;
            blackPlayer1 = playerQueue.front();
            playerQueue.pop();
            previousWinner = 'W';
        }
        if (gameResult == 'B') {
            winningTeam.player1 = blackPlayer1;
            winningTeam.player2 = blackPlayer2;

            std::swap(blackPlayer1, blackPlayer2);
            playerQueue.push(whitePlayer2);
            whitePlayer2 = whitePlayer1;
            whitePlayer1 = playerQueue.front();
            playerQueue.pop();
            previousWinner = 'B';
        }

        winningTeam.index = winningTeams.size();
        winningTeams.push_back(winningTeam);
    }

    int maxStreak = 0;
    for (const auto& team : winningTeams) {
        maxStreak = std::max(maxStreak, team.streakLength);
    }

    for (int i = 0; i < winningTeams.size(); i++) {
        if (winningTeams[i].streakLength == maxStreak) {
            std::string winner1 = winningTeams[i - maxStreak + 1].player1;
            std::string winner2 = winningTeams[i - maxStreak + 1].player2;
            int t1 = playerStreaks[winner1][i];
            int t2 = playerStreaks[winner2][i];
            if (t1 >= t2) {
                std::cout << winner1 << " " << winner2 << std::endl;
            } else {
                std::cout << winner2 << " " << winner1 << std::endl;
            }
        }
    }
}


