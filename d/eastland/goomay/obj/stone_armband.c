#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("stone armbands", "���߻���");
        add( "id", ({"armband","armbands" }) );
        set_short("a stone armbands", "���߻���");
        set_long(
        "An armband used by wrestler.\n",
	"�������������ĵĺڸ�ʯ���ɵĻ��ۣ�ͨ�������ĸ߼���ˤ����ʿ����\n"
        "�ʸ�����ġ�ˤ�Ǹ��������ֱ����ˣ���������Է����˵ĵ���������\n"
                );
        set( "unit", "��");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set("material","stone");
        set( "weight", 50 );
        set( "value", ({ 450, "silver" }) );
}
