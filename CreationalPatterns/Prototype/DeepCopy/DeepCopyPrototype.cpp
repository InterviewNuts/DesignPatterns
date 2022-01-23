#include"Game.cpp"

int main()
{
    GameApp ga1(11, "Racing Game", new MemberShip(true));

    ga1.setName(" Mohan");
    ga1.setId(659);
    ga1.playingGame();
    //! Now some players came, here , no need to create another game object & clone the state of the user1 and copy 
    //! field by field by client code. 
    //! Just cloning is enough, which is given by copy cotr in c++ , In java , we need to implement clone()
    //! Interface.
    //! here is the simple exam[le we can extend the GameApp to racing and shooting and can add a factory pattern to get the object
    //! there swalo copy and deep copy prototype. this is just a swalo copy

    GameApp ga2 = ga1;
    ga2.setName("hara");
    ga2.setId(234);
    ga2.playingGame();

    //! but the 

    return 0;
}