#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai mark", "��ʿ���� ");
        add( "id", ({ "samurai","mark","amulet"}) );
        set_short("samurai mark", "��ʿ����");
        set_long(@AAA
           һ��������ʿ��ֵ�λ�����£�ֻ�ж���ʿ���ش��͵���
           ����ӵ�д���
AAA
   );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 1 );
        set( "defense_bonus", 6 );
        set("material","element");
        set( "weight", 70 );
        set( "no_sale",1);
        set( "value", ({ 800, "silver" }) );
}
