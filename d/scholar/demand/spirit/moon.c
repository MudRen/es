#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(15);
	set_name( "moon spirit", "月光精灵" );
	add( "id", ({ "spirit" }) );
	set_short( "月光精灵" );
	set_long(
		"一个全身发出柔和的黄色光芒的精灵。\n"
	);
	set( "unit", "个" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
	set_skill( "dodge", 50 );
}

int my_action(object me)
{
       string str1="你见到一道黄光从天空直射而至，月光精灵从中走了出来，突然月光精灵全身放出一片\n金色光芒笼罩著你，你感觉一阵温暖，月光精灵又消失在黄光之中。\n";
       string str2="你见到"+me->query("c_name")+"神情专注的念著一些咒语，突然一道黄光从天空中直射而至，一只\n月光精灵从中走了出来，你见到月光精灵突然全身放出一片金色光芒笼罩"+me->query("c_name")+"之後，\n又消失在黄光之中。\n";
       string str3="HIY";

        seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"月光精灵对你说：没问题...我马上来帮你医疗!\n");
        me->receive_healing(15+random(15));
        END->bye_bye(me,this_object(),15,str1,str2,str3);
	return 1;
}
