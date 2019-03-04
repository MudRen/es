#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	seteuid( getuid() );
	set_short("������");
	set_long(
@LONG
������ī�������о���, ��Ի�����ɡ���ǽ�Ͽ̻��������󷨵����С�Ҫ����
�����Լ����󹥻��ķ���������Կ�����λ����һ���������صĲ�������������ģ��
��Щ�󷨣�������������ͷ��˼Ҫ���������Щ�󷨡�������Ҳ��������ȥ����ǽ��
��(wall)����Щ�󷨾�Ҫ��
LONG
	);
        set("item_desc", ([
             "wall": @LONG
ǽ�Ͽ�������ī������֮�أ������󷨾�Ҫ��
����������������������������������������
��   ��ϰ��һ����������֮�᷽��ѧϰ   ��
��   ���������ʱ���Լ���Ī���Σ��   ��
��   �������������ȥ��ϰ(study)��    ��
��   ==============================   ��
��                                    ��
��      1.  ����΢���� (two)          ��
��      2.  ����������� (three)      ��
��      3.  ��������� (four)         ��
��      4.  ���������� (eight)        ��
��                                    ��
����������������������������������������
     ��ʹ��(help_require)��ѯѧϰ��
     ������Ҫ�Ļ������ܡ�
LONG
            ]) );
	set( "light", 1 );
	set( "exits", ([ 
                "up" : "/d/scholar/scholar/storage",
		"down" : "/d/scholar/scholar/hall" ]) );
	reset();
}

void init()
{
        add_action("do_help_require","help_require");
	add_action("do_study", "study");
}

int do_help_require()
{
  tell_object(this_player(),@LONG
��������������������������������������������������
��==============================================�� 
��        ��                  ��������        �� 
��  1.  ����΢����         ��(embattle) >= 31 ��
��  2.  �����������       ��(embattle) >= 51 ��  
��  3.  ���������         ��(embattle) >= 71 �� 
��  4.  ����������         ��(embattle) >= 91 �� 
��==============================================��  
��������������������������������������������������
LONG);
  return 1;
}

int do_study(string str)
{
  int emb,ok,ok2=0,is_member=-1,flag;
  string *embat,msg;
  mapping known;

  if (!str)
    return notify_fail("��Ҫ��ϰʲ�� ?\n");
  emb=this_player()->query_skill("embattle");
  if (!emb || emb<=30)
    return notify_fail("�Բ�������󷨼��ܲ�������ϰ��Щ�󷨡�\n");
  known=(mapping)this_player()->query("embattle");
  if (known && sizeof(known)!=0) {
    embat=keys(known);
    ok2=1;
  }
  switch (str) {
    case "two":
       if (emb>30) {
         ok=1;
         this_player()->set("embattle/two",1);
       }
       msg="����΢��";
       break;
    case "three":
       if (emb>50) {
         ok=1;
         this_player()->set("embattle/three",1);
       }
       msg="���������";
       break;
    case "four":
       if (emb>70) {
         ok=1;
         this_player()->set("embattle/four",1);
       }
       msg="�������";
       break;
    case "eight":
       if(emb>90) {
         ok=1;
         this_player()->set("embattle/eight",1); 
       }
       msg="��������";
       break;
    default: return notify_fail("Syntax: study <����>\n");
  }; 
  if (ok2)
    is_member=member_array(str,embat,flag);
  if ((ok==1)&&(is_member>=0))
    ok=2;
  switch (ok) {
    case 1: write("����һ��˼������ϰ֮�ᣬ��ɹ�\��ѧ����"+msg+"��\n");
            break;
    case 2: write("���Ѿ���"+msg+"���ˡ�\n");
            break;
    default: write("����󷨼��ܻ���������"+msg+"��\n");
  };
  return 1;
}
