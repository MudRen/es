#include <../goomay.h>
inherit Mob_special;
int payed;
void init()
{
	::init();
	add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

void create()
{
        ::create();
        set_level( 5 );
        set_name( "the waiter", "店小二" );
        add( "id", ({ "waiter" }) );
        set_short( "店小二" );
        set_long(
@LONG
你看到一个十来岁的小伙子，戴著一顶青布小帽，笑容满面的脸上长了几颗
青春痘，一双溜溜的大眼睛显得十分灵动，他是本店的店小二，出了名的包
打听，只要你能了解他的需要，他一定会满足你的要求，当然，你也要先让
他满足才行。
LONG
        );
        set( "gender", "male" );
	set("race","halfling");
	payed=0;
        set_natural_armor( 25, 10 );
        set_natural_weapon( 6, 5, 11 );
        set_skill( "dodge", 80 );
        set_perm_stat("dex",10);
        set_perm_stat("str",10);
	set( "defense_type","dodge");
        set( "alignment", 150 );
        set( "wealth/silver", 20 );
        set("special_attack",(["damage_type" : "none","main_damage" : 5,
                                "random_dam" : 5 , "hit_rate" : 13]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"店小二用他的抹布望你身上抽来，拍的一声重重的打在你身上，你感到一阵剧痛..\n\n");
set("c_room_msg","店小二用抹布抽打");
set("c_room_msg2", "把他打得晕头转向 ...\n");
}
void ask_scribe()
{
        tell_object(this_player(),
        "店小二道：「这些当官的人架子大得很，等闲是见不著的，但是如果你是\n他们的上司，那就另当别论喽」\n" );
}
int ask_me(string str)
{
        string mon_name,subject;

        if (!str)
                return notify_fail(
                "要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");

        if (sscanf(str, "%s about %s", mon_name, subject) != 2)
                return notify_fail(
                "要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");
	if (mon_name!="waiter")
	{
		this_player()->command("ask "+str);
		return 0;
	}
        if (!payed) {
                write(
                "店小二笑道：「 客官 ... 总得意思意思吧 !! 了解吗？」 \n" );
                return 1;
	}

switch (subject) {
        case "hunter" :
        tell_object(this_player(),
	"店小二道：「猎人阿三啊，这几天没见他拿野味出来卖啊，鱼贩子宋九跟他很熟，\n"
        "你可以找他问问 ..」\n" );
                break;

        case "herb" :
        tell_object(this_player(),
	"店小二道：「说到这个药草啊，还不都是钱不多搞的鬼吗？大概是世德堂的\n"
	"老医生得罪他了，所以他打算不让他做生意了，谁知道呢？不过这世上如果\n"
	"有谁能劝的了钱不多的，那一定非绿珠姑娘不可了。」\n" );

                break;
	case "maid" :
        tell_object(this_player(),
	"店小二道：「你是说小翠这凶丫头吗？劝你最好别去招惹她，不过她对绿珠姑娘\n"
        "真的非常忠心，嗯 ～～听说她最近迷上了收集珍珠。」\n" );

		break;
        case "magistrate" :
			ask_scribe();
                break;
        case "captain" :
                        ask_scribe();
                break;
        case "scribe" :
                        ask_scribe();
                break;

        default : 
	write(
	"店小二笑道：「 客官 ... 虽然我不知道你想知道的事，可这也算一个问题啊」 \n" );
                break;
}
	payed = 0;
	return 1;
}

int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "付谁？多少钱？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "小二哥说道: 客官 ! 对不起，今年好像流行金币耶。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 50 ) {
                tell_room( environment(), 
                 "小二哥说道: 客官 ! 小的一条贱命难道只值这些钱吗？\n" ,
                        this_object() );
		return 1;
	}
	payed=1;
	tell_object(this_player(),
		    "店小二向你眨眨眼笑道：「那麽 ... 客官 !! 你想知道些什麽呢？」\n" );

	return 1;
}

