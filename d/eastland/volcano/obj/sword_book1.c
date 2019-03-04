#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "mar_short book", "���ǽ���" );
	set_short( "���ǽ���" );
	set("long",@LONG
���ǽ����Ľ��ס����ܶ�����(read mar_short book)��?
LONG);
	set( "unit", "��" );
	set( "weight", 1 );
	set( "no_sale", 1 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);  
}

void init()
{
        add_action( "do_read","read");
        add_action( "do_learn", "learn" );
}

int do_read(string arg)
{
  if( !arg || arg!="mar_short book" )
    return 0;
  tell_object(this_player(),@LONG
�㷭�����׵ĵ�һ�ţ�����д��
�����ǽ�����һ�ֶ����ͽ�����ǿ��������ʱ�ļ��ɣ����Ե���Ķ�����ʹ�õ���
����������Խ�̵ģ������ܷ��ӽ���������ҲԽ��............................
................................................................��
�ټ�������ȥ����һЩ�轣��ͼ���ˣ����룬�������ܳ���ȥѧϰ(learn mar_short
 book)���׽�����  
LONG);
  return 1;
}

void learn_book(object me,object obj)
{
  tell_object(me,     
 "����һ�������������ѧ����ǽ�����\n�������<enhant mar_short>��ʩչ������\n");
  this_player()->set("scholar_gonfu/mar_short",1);
  obj->remove();
  return;
}

int do_learn(string arg)
{
   object me;
   me=this_player();
   if( !arg || arg!="mar_short book" )
     return 0;
   if (!(me->query("class")=="scholar"))
     return notify_fail("������������ϸ����һ�������뻹�Ƿ������ˡ�\n");
   if ((me->query_skill("palaeography")< 75))
     return notify_fail("�㿴�˰��죬��һ���ֶ���������\n");
   if ((me->query_perm_stat("int")< 24))
     return notify_fail("�㿴�˰��죬�����е㶮�ˣ���ȴû�а취��⽣���ľ��衣\n");
   if (me->query("scholar_gonfu/mar_short"))
     return notify_fail("������˽���ǽ����ľ����ˡ�\n");
   tell_object(me,
     "����ϸ�ж���һ����ͻȻ������ᣬ�ԿձȻ�������......\n..............\n\n");
   call_out("learn_book",5,me,this_object());  
   return 1;
}
