#include "../story.h"
inherit ARMOR;
inherit SARM"OR";

void create()
{
        set_name("buddha amulet","����");
        add( "id", ({ "amulet" }) );
        set_short( "����");
        set_long(@C_LONG
һ���������ַ��ŵĻ���������֮�⣬����������Щ������ţ���ʱ��˸����â��
���â����е�һ�������ů�������Ǹ��ܺõķ��߲Ŷԡ�
C_LONG
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","cloth");
        set("the_one",1);
        set( "defense_bonus", 1 );
        set( "weight", 1 );
        set( "value", ({ 600, "gold" }) );
}



