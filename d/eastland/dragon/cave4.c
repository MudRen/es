
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
�������˶�Ѩʱ�㷢�ִ˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ������
��ʱ��һЩ��ֵ���ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�е�
��칹��һ�������ľ�ɫ�����㼸���������ںδ����˴��Ľ�����һʯ��(stele)��
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	   "stele" : @STELE
	   �˴���������Ľ��أ�����Υ������ߣ���ɱ���� !!!!
STELE
 ]));
    set("objects",([
       "guard":Ldmonster"guard"]));
	set( "light", 0 );
	set( "exits", ([
	    "west" : Lcave"cave20",
		"southeast" : Lcave"cave3"
	]) );
	set("pre_exit_func",([
	     "west" : "exits_open"]));

	reset();
}

int exits_open()
{
  if (present("guard",this_object() )){
       write ("����������ס�㲢��˵����ǰ���ǽ����㲻�ܽ���\n");
       return 1;
       }
   else return 0;
 }     
