#include <../takeda.h>
#include <stats.h>
#include <conditions.h>

#define LONG1 "����ѷ첻�󣬲�������㲻����Ļ�����ǿ���Լ���ȥ(enter)����\n" 
#define LONG2 "����ѷ챻һ���ʯͷ(rock)��ס��....\n"


inherit ROOM;

void create()
{
	::create();
	set_short( "��ֵĵط�" );
	set_long(@C_LONG
��������һ����ֵĵط���λ�Ⱥɽ������һ���ȵף�����ȫ������������������
�ͱڣ�������Ŀյ���һ�������������âħ����(circle)����ÿһ������ϣ���
����һ����ֵ�����(skeleton)�����õ����棬�ְ���һȦˮ�� (crystal)������
����ͱ��£�����������������϶(crack)������֮�⣬�ƺ�����ȥ·��
C_LONG	
	);
        set("c_item_desc",(["circle":
                "һ���޴����â��ħ��������һ������ĺ�ɫ����(color)���ɵģ� \n"
                "ħ����������ƺ��ۼ���ǿ���ħ����Դ��ʹ�ÿռ䷢������ֵ�Ť\n"
                "������ע�⵽��ħ������м䣬�ƺ���һ���޴��������ڣ�����춾�\n"
                "��̫Զ���㿴�Ĳ������...\n"
                 ,"skeleton":
                "����ϸ�۲���Щ�޴������\������������Щ�޴����棬���ǿն���˫��\n"                 
                "��ע����ħ��������ġ�������ת�����У����е�һ������\ͻȻת��\n"
                "ͷ�����㣬��е�һ��ë���Ȼ����ͷװ��û������\n"
                ,"crystal":
                  "һȦ��Ө��͸��ˮ�������Ǹ�����Ĺ��������е㲻̫���...\n"
                  "��˵ˮ�����м���ħ��������������\��������ǲŻ�����������\n"
                ,"color":
                "���ͷ�о���Щ����ɫ�����������֣�ʹ�õ����Ͽ�������ģ����Ǻܺÿ���\n"
                "�����ֿ���һ�������ţ�һ��Ѫ����ֱ��������ţ��㷢��ԭ�����ħ����\n"
                "����Ѫ���ɵģ���е�һ����ġ�\n"
                ,"crack":"@@query_crack"                            
                     ]));
        set_outside("eastland");
        set( "objects", ([
                "mob1" : "/d/noden/tomb/monster/small_centipede.c",
                "mob2" : "/d/noden/tomb/monster/small_centipede.c",
                "mob3" : "/d/noden/tomb/monster/red_spider.c",
                "mob4" : "/d/noden/tomb/monster/red_spider.c"
        ]) );
        reset();
}
void init()
{
add_action("do_enter","enter");
add_action("do_search","search");
}
string query_crack()
{
    if ( ! present("rock") )
          return LONG1;
              else
                  return LONG2;
}

int do_enter(string str)
{
    if ( str =="crack" ) {

  if ( present("rock",environment(this_player())) ) {
  write("�����϶��һ���ʯͷ��ס�ˣ���û�а취���ȥ...\n");
    return 0;
    }
    write("���ߵ��Ǹ���϶ǰ��һͷ���˽�ȥ..........\n");
    this_player()->move_player(TROOM"lair/lair4","�㿴��"+this_player()->query("c_name")+"���һ����϶��...\n");
    return 1;
    }
if ( str =="circle" ) {
  write("���߽��Ǹ���â��ħ����..........\n");
  write("��е�һ��˵�������ĸо���������һ���ݵ�����뿪���������...\n");
  (CONDITION_PREFIX + "weak")->apply_effect( this_player(), 2, 12 );
  this_player()->move_player(TROOM"lair/lair6","һ��ռ���Ŷ��ᣬ�㿴��һ����ͻȻ����\n");
  return 1;
  }
  return 0;
}
int do_search(string str)
{
if ( str =="skeleton" ) {
    write("����ϸ�����Щ����\���㷢�ִ����ǵ����ϣ���ͣ������Ѫ������Щ\n"
          "��Ѫ����һ������ǣ����������ħ�������ġ������������������Ѫ\n"
          "�����أ���ҡҡͷ��Ը�����������...\n");
          return 1;
          }
     return 0;
}          
          
int clean_up() { return 0; }
