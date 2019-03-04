#include <mudlib.h>
inherit OBJECT;

int inked;

string query_c_long()
{
   if ( inked )
     return  "���Ż���������ӡ�˹ű�����ֵ����֣�Ӧ��ȥ�Ҹ��������˿�����!!\n" ;
   else
     return  "���Ż����ƺ���������д�֡���������ӡ(squeeze)������\n" ;
}

void create()
{
	set_name("paper", "����");
	add( "id", ({ "paper" }) );
	set_short( "����" );
	set("long","@@query_c_long");
	set( "weight", 1 );
	inked = 0;
}

int query_inked() { return inked; }

void init()
{
	add_action( "squeeze_wall", "squeeze" );
}

int squeeze_wall(string str)
{
        object obj1, obj2;
        if ( !str || str=="" || str !="wall" )
          write("���Ҳ����ʵ��Ķ���!!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply_wall")==1) { 
              write("�㽫ֽ���ʯ���ϣ���˳���ؽ����Ϲ�����ӡ����!!\n");
              inked = 1 ; 
            }
            else
              write("�����ô��԰ɣ�����û�а취��ӡ��\n");
          }
        }
        return 1;
}
