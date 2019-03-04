#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(3);
	set_name( "dying man", "������������" );
	set_short( "������������" );
        add("id",({"man"}));
	set_long( 
             @LONG
�㿴�����ڵ��ϡ���һϢ�����ӣ�������ֺ��Լ�û������������ܻ���ڣ���ȫ
��Ϊ��Ҫ��һ������(secret)��������
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
        set("hit_points",1);
        set("no_attack",1);
        set ("chat_chance", 5);
        set ("chat_output", ({
             "�������ǿ�������˵���죬�Ѷ��俿��������֧�ֲ���ȥ��\n"
             }) );
        set ( "inquiry", ([
              "secret" : "@@ask_secret",
              ]) );
        call_out("disappear",100);
}

void disappear()
{
  tell_room(environment(),"������������˻���һ��\��������Ʈȥ��\n");
  remove();
}

void ask_secret(object who)
{
  if (this_player()->query_temp("ohio")<2) {
    tell_object(who,
      "������������˵�������Ա����ʴȣ���Ҳ������ʴȡ�\n");
  }
  else {
    tell_object(who,
      "������������˵����Ҫ���˵Ļ�����ȥ��ɽ���Ǹ�ͼ����\n");
   }
   tell_room(environment(),"����춡���������һ�������㿴�����廯��һ˿��������Ʈȥ��\n");
   this_object()->remove();
   return;
}
