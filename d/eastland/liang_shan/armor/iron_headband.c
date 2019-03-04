#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron headband", "��ͷ�����");
        add( "id", ({ "headband" }) );
        set_short( "iron headband", "��ͷ�����");
        set_long(
                "A iron headband for travelling monks .\n",
                "�η�ɮ�������Ļ��ߣ���Ϊ��������������ʿ����ע����\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "monk");
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               (["mental":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 350, "gold" }) );
        set("extra_stats",(["con":-1]));
        set("extra_skills",(["dodge":15]));
}



