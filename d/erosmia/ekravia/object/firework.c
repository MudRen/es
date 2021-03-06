#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

void	create()
{
	set_name("firework", "烟火");
	set_short( "烟火");
	set_long( @CLONG
这是一个烟火, 点燃 (light) 它, 你将会获得\许多乐趣。
CLONG
    );
	set("id", ({"firework"}));
	set("unit", "个" );
	set( "weight", 10 );
	set( "value", ({ 500, "silver" }) );
}

void	init()
{
	add_action("do_light","light");
}

int		do_light(string s)
{
	object ob;
	string s1,s2;
	string msg, cmsg;
	int color;
	object *usr;
	int	i, user_number;
	
	if (!s) return notify_fail( "你想点燃什麽?\n" );
	if ( (!ob = present(s)) || (ob != this_object())) 
		return notify_fail( "这里没有这种东西\n" );
		
	color = random (6);
	switch (color) {
		case 0  : s1= "HIR"; s2= "红"; break;
		case 1  : s1= "HIM"; s2= "粉红"; break;
		case 2  : s1= "HIY"; s2= "黄"; break;
		case 3  : s1= "HIG"; s2= "绿"; break;
		case 4  : s1= "HIB"; s2= "蓝"; break;
		case 5  : s1= "HIC"; s2= "紫"; break;
		default : s1= "HIR"; s2= "红";
	}
	emote( "$NS将烟火点著, 然後掩住耳朵迅速地躲到一边。\n", 
			this_player() );
	cmsg = "砰！的一声，一枚美丽的"+ s2 + "色烟火在天空中迸射开来。\n";
    			
    usr = users();
    user_number = sizeof(usr);
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( cmsg, s1, usr[i]));
    }
	remove();
	return 1;
}
