#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("brass armband", "臂环");
        add( "id", ({"armband" }) );
        set_short("降龙伏虎臂环");
        set_long(
                "这是一个由十八个神态庄严的罗汉扣合而成的臂环，各个施展著\n"
                "一套不同的拳法。\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "material", "monk" );
        set( "defense_bonus",1 );
        set( "armor_class",1 );
        set( "weight", 1 );
        set( "value", ({ 1, "gold" }) );
        set( "no_sale",1);
        set( "prevent_drop",1);
        set( "extra_skills", (["inner-force":5,"recitation":10]) );
        set( "equip_func", "to_equip");
        set( "unequip_func", "to_unequip");
}

int query_auto_load() { return 1; }

int to_equip() 
{
	this_object()->set("extra_look","@@looks");
	return 1;
}
int to_unequip()
{
	this_object()->delete("extra_look");
	return 1;
}
string looks()
{
	return set_color("$N戴著一个盘著十八罗汉的臂环, \n它除了是通过少林寺十八铜人阵的证明外, 更是强者的象徵 !!\n","HIW");
}
