#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
          set_name( "iron", "�ٶ�" );
          add( "id", ({ "iron" }) );
     set_short( "�ٶ�" );
	set_long(
                 "һ������ͨͨ���ٶ���������š���������������֣�\n"
	);
          set( "unit", "��" );
	set( "material", "cloth");
	set( "weight", 10 );
	set( "value", ({ 24, "silver" }) );
}
