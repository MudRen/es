#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_chainmail", "��ʿ����");
        add( "id", ({ "chainmail" }) );
        set_short("samurai_chainmail", "��ʿ����");
        set_long(@AAA
һ���͵ȼ���ʿ���������ף�ӦΪ���ǵ͵ȼ���ʿ��װ�� 
����Ҳ�����ṩʲ��÷�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 3 );
        set("material","heavy_metal");
        set( "weight", 200 );
        set( "value", ({ 450, "silver"}) );
}
