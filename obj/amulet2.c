#include <mudlib.h>

inherit ARMOR;

int do_fast_in();
int do_check();
int do_help();

void create()
{
	set_name( "workshop amulet","泥巴研讨会纪念胸章" );
	add("id",({"amulet"}));
	set_short( "泥巴研讨会纪念胸章" );
	set_long(@Long
这是1996 M.U.D. workshop 上送的虚拟纪念品, 上面有个漂亮的
勇者斗恶龙Mark。上面共有三个小按钮, 分别标示著(help), (login),
以及 (check), 如果你不清楚它们的功用, 建议你先按(press) help 
按键看看。
Long
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "prevent_drop",1);
	set( "prevent_get",1);
	set( "prevent_insert",1);
}

int query_auto_load()
{
	return 1;
}

void init()
{
	add_action("do_press","press");
}

int do_press(string arg)
{
	if (!arg) return notify_fail("你要按什麽?\n");
	if (arg == "login") do_fast_in();
	else if (arg == "check") do_check();
	else if (arg == "help") do_help();
	else return notify_fail("你要按什麽?\n");
	return 1;
}
int do_fast_in()
{
	tell_room ( environment(this_player()), this_player()->query("c_name")+
			"伸手按下泥巴纪念胸章上的一个小按钮, 但什麽事也没发生。\n",
			this_player());
	write ("你伸手按下泥巴纪念胸章上的一个小按钮, 但什麽事也没发生。\n");
	
     return 1;	
}		

int do_check()
{	
	write ("你的泥巴纪念胸章已经没有能源帮你快速进入ES了。\n");
	return 1;
}

int do_help()
{
	write(@Help
这个泥巴研讨会纪念胸章除了可以当做一般的防具使用外, 还可以帮助你
快速进入开放区域, 使用方法如下:
press check: 检查纪念胸章中的能量还能帮助你login几次。
press login: 立即进入 ES 开放区域。
当纪念胸章中的能量用完後, 胸章仍可当作一般的防具使用, 而且在quit
後不会消失。
Help
	);
}	