#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(10);
	set_name( "water spirit", "水精灵" );
	add( "id", ({ "spirit" }) );
	set_short( "水精灵" );
	set_long(
		"一个全身蓝色的精灵，头上还有著一小朵乌云。\n"
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
        string str1="你见到天空一朵乌云飘来，水精灵从中飘了出来，水精灵用手触摸你的伤口，你觉的一阵\n冰凉，水精灵又随著乌云飘走了。\n";
        string str2="你见到"+me->query("c_cap_name")+"神情专注的念著一些咒语，突然天空中飘来一朵乌云，一只水精灵\n飘了出来，你见到水精灵伸出手去触摸"+me->query("c_cap_name")+"的伤口之後，又随著乌云飘走了。\n";
        string str3="HIB";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"水精灵对你说：没问题...我马上来帮你医疗!\n");
        me->receive_healing(15+random(5));
        END->bye_bye(me,this_object(),10,str1,str2,str3);
	return 1;
}
