#include <mudlib.h>
inherit ARMOR;

void create()
{
        if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
        }
        set_name( "ice dress", "��������");
        add( "id", ({ "dress" }) );
        set_short("ice dress", "��������");
        set_long(@C_LONG
����һ���Ժ�������ɵ����¡�
C_LONG
        );
        set( "unit", "��");
        set( "type", "body" );
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
        set( "weight", 1 );
        set( "value", ({ 1, "silver" }) );
	set( "no_sale",1);
	set("prevent_drop",1);
}
void init()
{
        add_action("to_rest","rest");
}
int to_rest()
{
        object me;
        me = this_player();
        me->set("max_hp",3000);
        me->set("hit_points",3000);
        me->set("spell_points",320);
        me->set("force_points",3000);
        me->set("talk_points",600);
	write ("һ�ɺ���Χ������,����û����泩.\n");
        return 1;
}
