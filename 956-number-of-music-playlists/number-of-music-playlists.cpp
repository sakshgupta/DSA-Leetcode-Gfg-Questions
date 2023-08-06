#define ll long long int
class Solution {
public:
    int N,Goal,K;
    int mod =1e9+7;
    ll dp[101][101];

    ll solve(int usedSong,int currL)
    {
        if(currL==Goal)
            return usedSong==N;

        if(dp[usedSong][currL]!=-1) return dp[usedSong][currL];

        ll usedSongPlay = (solve(usedSong,currL+1) * max(0,usedSong-K))%mod;
        ll newSongPlay = (solve(usedSong+1,currL+1) * (N-usedSong)) %mod;

        return dp[usedSong][currL]= (usedSongPlay + newSongPlay)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        // two options: use new song or old song
        // for old song: make sure to use only after k songs have been played
        // for new songs: just use it and as we need to multiply it with total possibilities so multiply it with N-usedSong
        
        this->N=n;
        this->Goal=goal;
        this->K=k;
        memset(dp,-1,sizeof(dp));
        return (int) solve(0,0);
    }
};