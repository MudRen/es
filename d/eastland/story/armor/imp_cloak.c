#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of Wing race", "����������");
        add( "id", ({ "cloak" }) );
        set_short( "����������");
        set_long(@C_LONG
����һ����ǧ���˿���ƳɵĶ���ֹ�ϸ�£�����ͨ�磬�������ඬů��������
�ʼ��ˡ�
C_LONG
        );
        set("unit","��");
        set("type", "cloak" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set("defense_bonus", 6 );
        set("weight", 50 );
        set("extra_skills",(["meditate":10]));
        set("extra_stats",(["dex":-1]));
        set("value", ({ 210, "gold" }) );
}



