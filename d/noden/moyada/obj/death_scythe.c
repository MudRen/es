#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Controlled Death Scythe", "��������������");
	add ("id",({ "scythe", }) );
    set_short("��������������");
	set_long(
	    "һ�Ѻ�ʮ�ַ����Ĵ���������˵�������İ���������\n"+
	    "�������������(cropp)��? \n"
	);
	set( "unit", "��" );
	set( "weapon_class", 42 );
// set( "type", "shortblade" );
   set( "type", "longblade" );
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
    add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
     write( 
       "����������ధ���˵: �벻ҪŰ���ҡ�\n"
    );
    return 1;
}
