#include "../oldcat.h"

inherit OBJECT;

void create()
{
        set_name("stone key", "����ʯԿ��");
        set_short("����ʯԿ��");
        set_long( @LONG
    һ֧��Ư������ʯ���Ƴɵ�Կ�ס����������ֱ��  < insert ĳ�ط� > ����
���ض��Ķ�����
LONG    );
        set( "unit", "֧" );
        set( "weight", 20 );
        set( "value", ({ 50,"silver"}) );
        set("no_sale",1);
}

void init()
{
  add_action("do_unlock", "insert");
}

int do_unlock(string arg)
{
  object here,book;
  
  if (arg!="wall_hole")
    return notify_fail("�����˰��죬һ����Ҳû�С�\n");
  if (!this_player()->query_temp("can_insert_key"))
         return 0;
  here=environment(this_player());
  if (here->query("wall_box_for_mar_short"))
    if (present("wraith elder",here))
      return 
        notify_fail("�㷢�ְ����峤������ݺݵض����㣬ֻ�øϽ���Ķ��ӡ�\n");
    else   
      if (here->query("have_book")) {
        tell_object(this_player(),@LONG
�������ʯԿ�ײ��ǽ�ϵİ�����쬵�һ����Կ�ױ����˽�ȥ��������һ��С��
�ӡ���˳�־Ͱ�С���ӽ���������
LONG  );
        here->set("have_book",0);
        seteuid(getuid());
        book=new(OOBJ"sword_book1.c");
        book->move(this_player());
        this_object()->remove();
        return 1;
      }
      else {
        tell_object(this_player(),
          "�������ʯԿ�ײ��ǽ�ϵİ���������Կ���ֵ��˳�����\n"
          );
        return 1;     
      }
  return 0;      
}
