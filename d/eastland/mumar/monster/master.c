#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        ::create();
        set_level(10);
        set_name( "gonfu master", "��ͷ" );
        add( "id", ({ "master" }) );
        set_short( "��ͷ" );
        set_long( "�㿴��һ����ƨ�Ľ�ͷ���ڶ��±�ָָ���ء�\n" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", 300 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 70 );
        set( "wealth/gold", 20 );
        set_natural_weapon( 22, 9, 17 );
        set_natural_armor( 43, 20 );
        set( "natural_weapon_class2", 28 );
        set( "natural_min_damage2", 10 );
        set( "natural_max_damage2", 22 );
        set( "chat_chance", 5 );
        set( "chat_output", ({
                "��ͷ���±�˵��: ���������᱿���������������ȡ�\n",
                "��ͷ�����±�����: ������!!��Ϳ쵹�����!!\n",
                "��ͷ����˵: ��ʲ�ῴ!!û�������������!!��\n",
                "��ͷ�ò�м���۹������´����㡣\n"
        }) );
        set( "att_chat_output", ({
  "��ͷ���:��������!�������Ŵ�������!!���ҽ����ǵı��¶�������!!����\n",
        }) );
 
    equip_armor(OBJS"pants");
    equip_armor(OBJS"cloth02");
}
