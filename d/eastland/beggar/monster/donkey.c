#include "../dony.h"
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "donkey", "��¿" );
        add( "id", ({ "donkey" }) );
        set_short( "��¿" );
        set_long(@C_LONG
����һͷ�������Ĵ�¿������һ֧�۾��Ѿ�Ϲ����,�������Ҳֻʣ�¼���ϡ
ϡ���������, ����·��ҡҡ�ڰ�β��һ˦һ˦��,��!β�ͻ�������������!��
���㲻����Ϊ��,���������� ( mount ) ������ȥ����,����С����������Ů�ɻ�
�������㡻�Ľ����ء� 
C_LONG
        );        
        set( "unit", "ƥ" );
        set( "race", "monster");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "extra_look","$N������һͷ��¿�ϣ�����������ม�\n");
        set( "mountable", 1);
        set( "max_load", 2500 );
        set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
        set_c_verbs( ({ "%ş������, ��%sһ��", 
                        "%s��β����%sһ��",
                        "%s��������%sһҧ"}) );
        equip_armor(DARMOR"saddle");
}
void relay_message(string class, string msg)
{
  
     string who, str;
     object player;
          
     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)���˹�����", str,who )==2 ) {
        if( !player = find_player(lower_case(who)) ) return;
        if( (string)player->query("gender")=="female"){  
            tell_object(player,
               "��¿��ɫɫ���۹ⶢ������,�����������㡻�Ľ���!!\n");                 
            tell_room(environment(this_object()),
               "��¿�����������㡻����,��������һ��,��!ԭ������"+
               player->query("c_name")+"�����Ů���˹���!!\n",player);
        }
     }
}
void init()
{
    mount::init();
}
