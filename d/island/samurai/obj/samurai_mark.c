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
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set("material","element");
        set( "weight", 70 );
        set( "no_sale",1);
        set( "value", ({ 800, "silver" }) );
}
