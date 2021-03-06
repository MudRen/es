#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
string str1="你见到远处一个绿色的精灵站在一根草上飞了过来，草精灵将一片药草敷在你的伤口上，\n你觉的一阵刺痛，草精灵又随著风飞走了。\n";
string str3="HIG";

void create()
{
	::create();
	set_level(4);
	set_name( "grass spirit", "草精灵" );
	add( "id", ({ "spirit" }) );
	set_short( "草精灵" );
	set_long(
		"一个有著修长的身躯，全身泛著淡绿色的精灵。\n"
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
        string str1="你见到远处一个绿色的精灵站在一根草上飞了过来，草精灵将一片药草敷在你的伤口上，\n你觉的一阵刺痛，草精灵又随著风飞走了。\n";
        string str3="HIG";
        string str2="你见到"+me->query("c_name")+"神情专注的念著一些咒语，你见到远处一个绿色的精灵站在一根草\n上飞了过来，草精灵将一片药草敷在"+me->query("c_name")+"的伤口之後，又随著风飞走了。\n";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"草精灵对你说：没问题...我马上来帮你医疗!\n");
        me->receive_healing(6+random(2));
        END->bye_bye(me,this_object(),4,str1,str2,str3);
	return 1;
}
