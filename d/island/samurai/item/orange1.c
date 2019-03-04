#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("orange","柳丁");
	add( "id" , ({ "orange" }) );
	set_short("orange" , "柳丁");
	set_long(@AAA
	一个新鲜的柳丁，由於老板的坚持你必须当场吃掉它
AAA
	);
   	set("unit","颗");
   	set("weight", 2);
   	set("value",({ 15, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
		tell_object(owner, can_read_chinese()?
			"你吃下一颗新鲜柳丁，感觉很满足。\n":
			"You drink a cup of Special Wine....\n"
		);
		tell_room( environment(this_player()), ({
			owner->query("cap_name")+" drink a cup of Special Wine....\n",
			owner->query("c_name")+"吃下一颗柳丁看起来好像"
			"很满足的样子\n"}), this_player()
		);
		owner->receive_healing( 5+random(5) );
	remove();
}
