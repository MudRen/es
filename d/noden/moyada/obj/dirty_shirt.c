#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "dirty shirt", "�����" );
	add( "id", ({ "shirt", }) );
	set_short("�����");
	set_long( @C_LONG
    һ������ͨ�Ĳ�֯�ɵĳ���, �����ֳ�, ��֪���ûϴ�ˡ�
C_LONG
	);
	set( "unit", "��" );
        set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "value", ({ 10, "silver" }) );
}
