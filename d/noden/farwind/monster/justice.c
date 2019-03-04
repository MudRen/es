// justice.c
// The justice of the peace of Farwind. 
// Nominally performs marriages, although the marriage code is in the
// courthouse and not in the monster.

#include <mudlib.h>

inherit MONSTER ;

int time=0;
void create ()
{
	::create() ;
	set_level(19);
	set_name("allynia", "��������");
	add ("id", ({ "justice", "judge" }) ) ;
	set_short("���ٰ�������");
	set_long(
		"��������һ�������Ⱥž���Ϊ�����ֻ���\n"
	);
	set ("no_attack", 1);
	set ("gender", "female");
	set ("race", "imp");
}

void init()
{
        ::init();
        add_action("wedding_word","wedding");
}

int wedding_word(string str)
{
	object ppl,ppl2;
	string who1,who2;
	int crazy;
	if ( !wizardp(this_player()) ) return 0;
        if( !str || sscanf( str, "%s to %s", who1, who2 ) != 2 )
                return notify_fail( "Syntax : wedding <boy> to <girl>" );

	if (!present(who1,environment()) || !present(who2,environment()) )
	return notify_fail( 
	      "����ҡҡͷ���� ���ɻ����ﲻ������ !!��\n" );

	if ( time==0 )
	{
	tell_room( environment(), 
	"����ׯ�ϵض��� "+capitalize(who1)+" ˵������ "+capitalize(who1)+" !! ��Ը��һ�����չ� "+capitalize(who2)+" ��\n"+
	"���۹η����꣬reboot �� crash ������ƴ��׬Ǯ�� "+capitalize(who2)+" �ӻ���\n"+
	"���Ҿ��Լ����е�����������������ʹ�������𣿡�\n" ,
        this_object() );
		time=1;
		crazy=0;
	return 1;
	}

        if ( time==1 )
        {
        tell_room( environment(), 
	"����תͷ���� "+capitalize(who2)+" ˵������ "+capitalize(who2)+" !! �����Ը���Ϊ "+capitalize(who1)+" �����\n"+
	"��ŵһ��һ��������������������Ǯ������ reboot �� crash ��\n"+
	"������� "+capitalize(who1)+" �����ԣ�ֱ���赹�ڵ���ǰ�𣿡�\n" ,
        this_object() );
                time=2;
        return 1;
	}

        if ( time==2 )
        {
        tell_room( environment(), 
	"����΢Ц��˵��������ϲ���� !! "+capitalize(who1)+" �� "+capitalize(who2)+" !!! \n"+
	"���������ǳ�Ϊ��ʽ�ķ��ޣ��뽻����ָ��ͬʱ�����˵Ǽ�� !!��\n",
        this_object() );
                time=3;
        return 1;
	}

        if ( time==3 )
        {
        tell_room( environment(),
	"�������ŷ���ͻȻ�����������ֽе����� ��Ҫ������ !! �������������� !!��\n"+
	"˵�������ɷ�˵�ı��� "+capitalize(who1)+" ���� ... �� ...�� ...\n\n"+
	"�������� ...... ��һ� ... �Ǹ�... ���� !!!! \n\n" ,
        this_object() );
                time=0;
	command("hold "+who1);
	command("kiss "+who1);
        command("lkiss "+who1);
        command("lkiss "+who1);
	command("lkiss "+who1);
        return 1;
	}

	return 0;
}
