#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("ice sting","����");
        add("id",({"sting"}) );
       set_short("����");
       set_long(
         "�����ñ����Ƴɵķ������б�����͸���ķ����Եò���Ѱ����\n");

        set( "unit", "��" );
        set( "weapon_class", 14 );
	set("type","shortblade");
        set( "min_damage", 8 );
        set( "max_damage", 16 );
	set( "weight", 80 );
        set( "value", ({ 540, "silver" }) );
}
