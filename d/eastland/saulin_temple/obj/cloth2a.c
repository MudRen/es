#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("zu-lai plate","��������");
    add("id",({"zu-lai","plate"}) );
    set_short("��������");
	set_long(
	"���ǽ�ս����ݱ�ޱ�����ĥ���ڶ���ջ��ļ���,�ֳ��������С�\n" 
	);
	set( "unit", "��" );
	set( "weight", 150 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 230, "gold" }) );
}
