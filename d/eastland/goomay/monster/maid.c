
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "maid", "婢女" );
        set_short("婢女");
        set("unit","个");
        set_long(
@C_LONG
    她是一位很可爱的小女孩，梳著三丫头髻，一副什麽都不怕的样子。
她正在堂前打扫，顺便帮她美丽的女主人看守门户，不过像她这样年纪
的小女孩，一定很喜欢一些新奇的玩意儿。
C_LONG
);
        set ("gender", "female");
        set ("race", "human");
		set("no_attack",1);
}
void init()
{
        add_action( "kill_me", "kill");
}

int kill_me(string arg)
{
  if (arg=="maid")
	{
	tell_object(this_player(),
		"婢女生气地道 ： 「喔 ～～好不要脸 !! 欺负我年纪小吗？出去出去 !!」\n"
		"说著就把你推出门外。\n" 
		);
      this_player()->move_player( Goomay"rich_house", "SNEAK" );
        tell_room( Goomay"rich_house", 
         this_player()->query("c_name") + "被人从绿珠楼轰了出来。\n"
        ,this_player() );
        return 1;
	}
	else 
	this_player()->command("kill "+arg);

}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
那婢女接过珍珠戒指对光一看。她啐了你一口道：「这根本是假货嘛 !! 
你花了多少冤枉钱买的？ 」她把戒指往地上一掷，瞧也不瞧一眼。
RING
	);
        command("drop "+name);
        return 1;
}
     tell_object(me,
@MISSION
那婢女接过珍珠对光一看，两颗眼珠突然发出光芒。
她叫道：「这好像是真品呢 !! 让我来好好鉴定鉴定 。」
说著她就不再理你了。
MISSION
	);
		item->remove();
		this_player()->set_temp("give_pearl",1);
        return 1;
}
