#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "red silk du-do","��еز���Ƕ�" );
        add( "id", ({ "cloth", "du-do" }) );
        set_short( "��еز���Ƕ�");
        set_long(@LONG
һ����ƿɰ���С������ĶǶ�������ɫ�������ɫ���أ�������ƣ���Ҫ������
����ͼ�����Ӳ���֮�����ƴ�Ķ��ɡ�
LONG);
        set( "unit", "��" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 20);
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
}
