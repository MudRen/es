//File: doshy_temple.c ���ʴ�ʿԺ

#include "saulin_temple.h"

inherit ROOM;

void create()
{

       ::create();
	   set("kissed",0);
       set_short("Doshy temple","���ʴ�ʿԺ" );
       set_long( @LONG_DESC
empty
LONG_DESC
                 ,@C_LONG_DESC
�����ǹ����ն������Ĺ�����ʿ�ĵط�����ͬ������������ط����ǣ� 
��֪��Ϊʲ�����ÿ�շ���ɮ������ɨ֮�⣬���Ｘ�����˼�������Ժ�ڹ�
���һ��������(statue)��ִƿ���������������أ�����ʮ��ׯ����ȴ��
���߷�������������һƬ�żŵ����֡�
C_LONG_DESC
               );
       set( "light", 1 );
       set("exits",([
		"north" : SAULIN"forest1",
       ]) );
       reset();
       set("c_item_desc",([ "statue" : @C_LONG
������ǰȥ��ϸ��������������ͻȻ�۾�һ������ǰ��Ȼ������һλ
��ò�ٸ�(woman),���������ĵ�Ц������ͣ�������ǶԹ������ǵķ���
�����㣬��е�һ��ǰ��δ�е��������̲�ס����ǰ����(kiss)����
C_LONG
       ]));
}

void init()
{
	add_action( "kiss_woman", "kiss" );
}

int kiss_woman(string arg)
{
	if( !arg || arg !="woman" )
      return notify_fail(can_read_chinese() ?
    	"���̬�� ! ��ǽ����\n" :
		"kiss what ? You stupid nut ?\n" );
    if( this_object()->query("kissed") )
      tell_object(this_player(), can_read_chinese()?
        "���ٸ����һ��ת����ӣ�ɫ�ǰ�! ɫ�ǰ�! ���˰�! ���˷��� ����\n"+
        "���ʱ�����ֽţ�ת����ܣ�û�뵽һͷײ��ǽ�ϣ�ԭ��ֻ�ǻ��롣\n" :
        "The woman run away and scream : Help !! Colorwolf !\n"
      );
	else {
      tell_object(this_player(), can_read_chinese()? @SHADOW_OUT
��¶����ɫ�ǵ�����������ǰȥ������λ�ٸ����ס��ף�����ëë�ģ��ѵ���Ů
�˳��������� ! �㶨��һ�������ﱧ��������һֻ�����۵ĺ��ꣿ

��������һЦ������ ! �ҵ���þ��� ! ������ !! ����������������� !

SHADOW_OUT
   : "The fox shout to you : Oh ! come on baby ! I need your blood !!\n"
      );
      new( SAULIN_MONSTER"fox" )->move( this_object() );
      this_object()->set("kissed",1);
    }
    return 1;
}

void reset()
{
    ::reset();
    set("kissed",0);
}
