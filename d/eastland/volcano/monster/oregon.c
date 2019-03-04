#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "Oregon", "���ո�" );
	add( "id", ({ "oregon" }) );
	set_short("���ո�" );
	set_long(
		"�����ڻ�ɽ����̽��ʱ��ץ�ġ�"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 800 );

	set("max_hp", 200);
	set("hit_points", 200);
	set( "wealth/silver", 40 );
        set_natural_armor( 10, 3 );
}

void give_mark(object me,object ore)
{
  tell_object(me,@LONG
������Ҫת���뿪ʱ�����ո�ͻȻ��ס�㲢˵�������ף�����Ӧ���������ɡ��ұ�����
�����ʱ����һ�����������������ˣ������ֵܺ����ʱ˵�Ļ������ݴ������ʦ��
���˵����������ȹ�һ������᰻ʳ�͵�����ʳǽ���ɱ�����˵Ĵ������λ���������
��һ���ӻʹ��ڱ�������ġ��������š�����ϧ���Ǽ�������ֻ��ħ���������У��Խ�
��ʵ���ǲ��У�������Ҳû��ʲ�����ܹ��͡�������һֱ���������û�á����������
ȥ͵���Ǳ����ţ��������ѧ��Ļ���һ����������ô�����   
LONG);
  me->set_temp("known_book_of_sword",1); 
  ore->remove();
  return;
}

int accept_item(object me, object item)
{
    string name;
    object ob1;
        
        name=(string)item->query("name");
        if ( !name || (name!="ohio ring") ) {
          return 0;
        }

	tell_room( environment(),
          "���ո���"+me->query("c_name")+"�ݵ���˵��: лл�������ң�\n"
	, me );
    tell_object( me, 
        "���ո�˵����! �������ֵܵĽ�ָ��\n"
        "���ո�����ݵ���˵��: лл�������ң��������Ѿ��ڵص������ˡ�\n");
        ob1 = new( OOBJ"oregon_ring" );
        ob1->move(this_object());
        ob1->set(me->query("name"),1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        item->remove();
        tell_object(me,"���ո�˵�����뽫�����ָ��ȥ����������֪�����Ѿ������ˡ�\n        ��Ҳ�����ˣ��ټ� !\n\n");
        command("wave "+lower_case((string)this_player()->query("name")));
        if (me->query("class")=="scholar")
          call_out("give_mark",2,me,this_object());     
        else 
          this_object()->remove();
        return 1;
}
