//��ʱ�����鲻��ʱʹ�õ����, ����ʮ������, ȡ������������.
#include <body.h>

inherit OBJECT;

void create()
{       
	set_name("spirit_stone","����֮ʯ" );
	set_short("����֮ʯ");
	set_long(@LONG
	
һ�鵭��ɫ��͸���Ľᾧʯ����˵�ܰ������л�ʧȥ�ľ��顣(touch spirit_stone)��

LONG);
	set("unit","��");
        set("prevent_get",1);
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg != "spirit_stone")
    return 0;
  if (!this_player()->query_temp("summon_rest")) {
    write("����֮ʯ΢΢������һ�£�����û�з����κ����顣\n");
    return 1;
  }
  write("����֮ʯ������ʵĹ�â��ʹ��ָ��л������������\n");
  this_player()->delete_temp("summon_rest");
  return 0;   
}