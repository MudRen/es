
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The squire of the dwarf village","���˴���Ĺ㳡");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ĵ�㳡��,���������ǳ���ƽ���������,�����Ǿ����ڴ˵�
���漰��Ϸ.������һ���ܴ��ˮ��(pool),�ǰ�������ˮ����Դ ,��ˮ����������һ��Ʈ
���ķ���(house),�㲻������Ϊ�����ܸ��ڿ��ж���������.��ˮ�����Ա���һ����־(si
gn),�����ƺ�д��һ������.
CLong
    );
    set("c_item_desc",([
        "pool":"һ����ˮ��,��춰��˵�����ˮȡ춴˵�,���Դ�ˮ����ֹ��Ӿ.\n",
        "house":"һ��Ʈ���ķ���,��������ֵ�����,����ע��������ʱ��,�㷢����һ\n"
                "����Ĺ��ߴ��������˳���.\n",
        "sign":"\nOSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
               "O              Ʈ��֮��,�������                        O\n"
               "O              �ش�(answer)����,������                O\n" 
               "O              ...........���� ����(Annow)              O\n"
               "OSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
                ]) ); 
    set("exits",([
                "west":Deathland"/village/v22",
                "east":Deathland"/village/v42",
                "south":Deathland"/village/v31",
             ]));
    ::reset();
}

void init()
{
     add_action("to_answer","answer");
}

int to_answer(string str)
{
    if (!str ||str!="intelligence")
    return notify_fail(
           "�����д���һ��Ц��,˵:�޴������޴��Ĵ�.\n");
    else
           write("һ����͵Ĺ��߰��㴫��������С����.\n");
           this_player()->set_explore("deathland#26");
           this_player()->move_player(Deathland"/village/v33",({
           "һ�����������%s,Ȼ��������ʧ��.\n",
           "%s���͵�����.\n"}),"" );       
           return 1;
}  
   
