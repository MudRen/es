#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("policeman's hat","��ɴñ");
        add( "id", ({ "hat" }) );
        set_short( "��ɴñ");
        set_long(@C_LONG
һ���÷����鲼��ɴ���Ƴɵĺ�ɫñ�ӣ�������״�е���Ѽ��ñ�����滹��������
���̡��������׭�֡�
C_LONG
        );
        set( "unit","��");
        set( "type", "head" );
        set( "material","cloth");
        set( "armor_class",7 );
        set( "defense_bonus",1);
        set( "weight", 50 );
        set( "value", ({ 1500, "silver" }) );
}



