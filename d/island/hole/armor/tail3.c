#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Dragon Scute Tail","����β��" );
	add( "id",({ "tail" }) );
	set_short( "����β��" );
	set_long(@LONG
	����һ����������Ƭ�����β�ף��и߶ȵķ�������
LONG
	);
	set( "unit","��" );
	set( "type","tail" );
        set( "material","leather" );
	set( "weight",100 );
	set( "armor_class",10 );
	set( "defense_bonus",3 );
	set( "value",({ 450,"silver" }) );
}