#include "../story.h"
inherit ARMOR;
inherit SARM"OR";

void create()
{
        set_name("twelve-god amulet","ʮ���춼����");
        add( "id", ({ "amulet" }) );
        set_short( set_color("ʮ���춼����","HIC"));
        set_long(@C_LONG
һ����������Ļ�������������������ɷ��裬�����Ծ������㿴����д����ʲ��
��
C_LONG
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","cloth");
        set("the_one",1);
        set( "defense_bonus", 1 );
        set( "weight", 1 );
        set( "value", ({ 5050, "silver" }) );
}



