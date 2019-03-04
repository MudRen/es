#include "../moyada.h"

inherit MONSTER;

#define MAX 10

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "Anteater", "ʳ����" );
	add ("id", ({ "anteater" }) );
	set_short( "ʳ����" );
	set_long( @LONG
һֻ������ʳ���ޣ���֪���û��ʳ�ˣ����������ݰͰ͵ģ��ÿ�����
LONG
	);

    set( "alignment", 400);
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 17);
	set ("max_hp", 240);
	set ("hit_points", 240);
	set_natural_weapon( 20, 10, 20 );
	set_natural_armor( 45, 10 );
	set( "persuing", 1);
	set( "death_msg", "ʳ���޿���˵: �Һ����� .... Ȼ�������!\n" );
	set( "weight", 400);
	set( "exp_reward", 700 );
    
	set ("chat_chance", 15);
	set ("chat_output", ({
	    "ʳ����˵: �ö��!\n",
	    "ʳ����˵: �þ�û���������ˣ��ǲ��Ƕ�������?\n",
	    "ʳ����˵: ���ĵĴ�ү����ֻ���ϸ��Һ���!\n",
            "ʳ����˵: û�л�����ϣ�ι(feed)�����ϵ�ʬ��Ҳ�У�\n",
	    }) ); 
	set ("att_chat_output", ({
	    "ʳ����˵: ��Ҫ�����ˣ����ﻹ���ң�\n",
	    "ʳ����˵: ������! �۸���С�� ����\n",
	    }) );
	set_c_verbs( ({ "%sҧ%s", "%s��%s", "%s����ײ%s" }) );
	set_c_limbs( ({ "����", "צ��", "��", "ͷ", "β��", "��ͷ", }) );
}
/*

void relay_message(string class, string msg)
{
      string who,tmp;
      object obj;

      if ( sscanf( msg, "%s(%s)���˹�����", tmp,who )==2 ) {
        obj = present(lower_case(who), environment(this_object()) );
        if( !obj ) return;
        if( (string)obj->query("race") == "ant" ) {
          tell_room( environment(this_object()) , 
            "ʳ����˵: ����!!! �о��ˣ��ԹԵı��ܣ��ú����ҳ԰�!\n"+
            "ʳ����һ�ھͰ�"+obj->query("c_name")+"���¶��ˡ�\n"
            , this_object()
          );
          obj->remove();
          call_out( "to_emote", 1, this_object() );
        }
      }
}
*/

void init()
{
    add_action("to_feed", "feed");
}

int is_a_corpse( object obj )
{
    if( (string)obj->query("name")=="corpse of ant" ) return 1;
    return 0;
}

int to_feed( string str )
{
    object player, *corpse;
    int left, i;
    
    if( !str || str == "" )
      return notify_fail("ι˭ ?\n");
    if( str != "anteater" )
      return notify_fail("û��������������� ��\n");
    player = this_player();
    left = MAX - (int)player->query_temp("anteater");
    corpse = filter_array( all_inventory(player),
                           "is_a_corpse", this_object() );
    i = sizeof( corpse );
    if( !i )
      tell_object( player,
        "ʳ���޺ܲ����˵ĵ�����˵: ����ʲ��ι��?\n" );
    else {
      while( i-- ) {
        if( (string)corpse[i]->query("type")=="ant" ) {
          tell_object( player,
            "ʳ���޸��˵İ�"+corpse[i]->query("c_name")+
            "���¶ǲ�¶������ı��顣\n" );
          left--;
          corpse[i]->remove();
        } else {
          tell_object( player, 
          "ʳ���޸��˵İ�"+corpse[i]->query("c_name")+
            "���¶ǵ�ȴ¶���ѿ��ı��顣\n" );
          corpse[i]->remove();
        }
      }
      if( left <= 0 && (int)player->query_quest_level("anteater") < 1 ) {
        tell_object( player,
          "ʳ���������˵: лл��! �ҳԱ���!\n"
          "   [ �����ʳ���ޣ���� 4000 �㾭��ֵ��]\n" );
        player->finish_quest("anteater",1);
        player->gain_experience(4000);
      } else if( (MAX - left) > (int)player->query_temp("anteater") ) {
        tell_object( player, 
          "ʳ���޸��˵�˵: лл��! �úóԣ��һ�Ҫ��\n" );
        player->set_temp("anteater", MAX-left);
      } else
        tell_object( player,
          "ʳ����ʧ����˵: �����óԣ���û�б��ֵ�?\n" );
    }
    return 1;
}

void to_emote( object obj )
{
      tell_room( environment(obj), 
            "ʳ����˵: �ó�!!����û��?\n" , obj
      );
}

