#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "����ѥ");
        add( "id", ({ "boots","boot" }) );
        set_short("@@color");
        set_long(@C_LONG
����ѥ���������д����λ�����磬ֻ��ͬʱ������������ʮ��������ɮ��
�Żᱻ�䷢��ѥ�����������ư��ͼ�ڣ����ý�˿����ȥ�ģ���˫Ь������
�������� ( Odin,Inc )       
C_LONG
        );
        set("material","cloth");
        set( "unit", "˫");
        set( "type", "feet" );
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "weight", 35 );
        set( "value", ({ 1001, "silver" }) );
        set( "no_sale", 1 );
}
string color()
{ return set_color("����ѥ","HIY"); }