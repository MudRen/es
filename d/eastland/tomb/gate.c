#include <almuhara.h>
#define MAX_DRAGON 4
inherit DOORS;
inherit ROOM;
void create()
{
	::create();
	set_short("地下石门");
	set_long( @LONG_DESCRIPTION
你现在来到一个宽阔的石室，这儿似乎是地道的终点。墙壁上散出一股柔柔的光芒，
映著室内的景物，气氛显得格外诡异。在你面前是一扇巨大的石门，石门上两只栩栩如
生的巨龙彷佛要破壁而出，狰狞的面目令你不寒而栗。在盘踞的双龙口中似乎有一个小
洞(hole)，你情不自禁地想走上前看个清楚。
LONG_DESCRIPTION
	);
        set( "light",1 );
        set( "mob_num",0 );
	set( "exits", ([ 
		"north" : TOMB"/inner1",
		"up" : TOMB"/down3"
		]));
	create_door( "north","south",
		   (["keyword" : ({"door", "stone"}),
			"name"    : "stone door",
			"c_name"  : "大石门",
			"c_desc"  : "一扇超大的石门，门後不知道有什麽玄机...",
			"lock"    : "TOMBKEY_1",
			"status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
	      	"hole" :@C_ITEM_DESC_1
在你小心翼翼地清除了洞周围的灰尘、杂物後，发现这是个浑圆的小凹槽，好像
可以放(put)什麽圆圆的小东西。嗯 !! 凹槽上方还刻著一行字(writings)。
C_ITEM_DESC_1
,		"writings" :@C_ITEM_DESC_2
『 先皇陵寝 ， 擅入者死 ！！』 哇，难道这里就是传说中东方皇帝的陵墓 ？！
C_ITEM_DESC_2
	   ]));
	   set( "pre_exit_func", ([
	   	"north" : "loop_exit" ]) );
           reset();
}

void init()
{
	add_action( "do_place", "put" );
}

int do_place (string str)
{
	object player,ob;
	string orb;
	int i;
    
    	player = this_player();
    
	if ( !str || str!="orb into hole")
		return 0;

	ob = present( "golden dragon orb" , player);
	if(!ob) {
		tell_object(player,"你身上没有适合的东西。\n");
		return 1;
	}

 	tell_object( player, 
		    "\n你把金龙珠放进小洞里。\n"
		    "\n突然传来一声巨响，大石门缓缓地打开了\n");
	tell_room( environment(player), 
		player->query("c_cap_name") + "把一颗小东西放进洞里。\n" 
		"\n突然传来一声巨响，大石门缓缓地打开了\n",
		player );
        set_status("north","open");
        update_link("north");		
 	player->set_temp("DRAGON_ORB",1);			
       	ob->remove();
       	return 1;
}

int loop_exit()
{
	object player;
	
	player = this_player();
	if ( !present("golden dragon",this_object())) {	
        if ( query("mob_num") < MAX_DRAGON ) {
		
                if ( !player->query_temp("DRAGON_ORB") ) {
                tell_room( this_object(),
                "\n石门上两只巨龙突然眼睛一亮，张牙舞爪地向你飞了过来！！\n"
                         );
                new(MOB"/dragon")->move(this_object());
                new(MOB"/dragon")->move(this_object());
		this_object()->add("mob_num",2);
                return 1;
		}
                else    return 0;
	}
	}
	if ( !player->query("player_invisible") && present( "dragon", this_object() ) ) {
		write("金龙盘旋在北方，使你无法进入。\n" );
		tell_room( this_object(), 
			sprintf("%s想往北走，却被金龙挡住！\n", player->query("c_cap_name"))
		, player);
		return 1;
	}
	return 0;	 	
}	
