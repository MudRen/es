#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥����" );
   set_long(@ANGEL
�������ǰ����ʿ�Ǳ���ָ������ǧ��¥����ڣ�������¥�и���Ũ��
���ձ�ʽ��ζ���㻹�����ŵ�һ�ɺ�̴ľ����ζ���ƺ�ǧ��¥����\��\��ĺ�
̴ľΪ���ģ��ڴ�¥�������������ŵ�ӣ������ʹ�������¥������������
������һ����
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2",
	        "guard2":MOB"guard2",
	        ]) );
        set( "exits", ([
    "south" :MR"inn02",
    "north" :MR"inn04",
    "west"  :MR"tree01"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "��̴ľ��",
                  "c_desc"  : "һ���ú�̴ľ���ţ������þ�ϸ���ֹ�\n"
                              "���һ����������\n"
                  ]) );
                            
         reset();                     
}

