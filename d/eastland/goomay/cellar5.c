
#include <goomay.h>

inherit ROOM;

void create()
{
	::create();
	set_short("�ض�");
	set_long( @LONG_DESCRIPTION
��������λ�һ��������ͨ���У�����ͨ����������\��ú����̿�ң�
ͨ����������ɵ��ŷ���һ�����Ļ�¯������������ԭ��������һ��������
���ӵ������Ĵ��Ҷ��Ĺ��߿�����ԭ���������ƺ��ߵĺܴ�æ��������Ҳ��
��������������û���κε�͸���ף����ǲ�֪�������������ȷ�һ����ش�
������о���������....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar4" ,
		"west" : Goomay"cellar6" ,
	]) );
	set( "objects", ([
	"fire_element" : Mob"fire_beast", ]) );
        set("exit_suppress", ({ "west" }) );
	set("pre_exit_func",([   "west"  :  "to_pass" ]) );
        ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("fire_element")) ) {
     write("һ��ħ��ǽ�赲ס���ȥ��.\n");
     return 1;
   }
   else {
     write("��������������һ�����������,�����׵�ͨ��ħ��ǽ.\n");
     return 0;
   }
}
