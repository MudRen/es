ħ��۹��ż�

	���� Lilia (athena@cs.nthu.edu.tw)


I. ���±�����д���ƻ�

	�Ŵ�ħ�彨����һ���Ӵ�ĵ۹����۹������޶˵��ɵ�����ʧ��ʹ����
    �����㿪ʼ��������ʧ��ԭ������Ϊ�۹�����ʦ��Ծ�������һ����ǰ��
    ���ѣ���������˾ϣ������������������������ľ��棬���ǲ�û�гɹ���

	��Ҿ�����֪��������ߣ�Ҫȡ���߸���ӡ��ͨ�����Ԫ�����ͨ��
    ȥ��ħ�������Ů�� (:p) �õ��������������Ȼ����������������˶���
    �˼�ǧ���ˡ������Լ��õ�Щ�ô�Ҳ�ǲ����� :)

	ԭʼ�ļƻ�����������Ʒ��� README �Լ�  quest �������������
    �ʵ�����������ѣ����ܻ�ֻ����ҽ��������ҵĽ��͡���Ȼ����Ҫ�ɸ���
    ��� arch �϶��Ƿ���Լ��� :p �����������������������Ϊ׼��ԭʼ��
    ����е������뻯 :p

	��� quest �����趨��  10 �����ϵ���ҿ��Բ��Ѵ���֮����ɣ���
    ���Һ����е��ֹۣ�Ŀǰ���ԵĽ��һ����Ϊ�����Ŀ̫�����ˣ��������
    λ arch ��̧���ֶ� QC ��ֻ�۱�ֻ�۰ɺǺ� *smirk*


II. ��������� (������Ŀ¼ /u/l/lilia/ruin/room)

	�ɷ�ӡ֮�� (sealroom.c) �����ż���ڣ��߹�ˮ������Թ� (en*.c)
    �������� (camp.c)��ȡ��ħ���ֵ�����������˹������ (rose*.c)��·
    �ϵĳ��ھ�ͨ��ŵ�ٴ�½Զ�������С�� (11,6.noden.c)��

	��˹���������д�ͼ��� (lib*.c) ��������̳ (altar.c)���⿪��ͼ
    ��ݴ��� (lib0.c) �ڵĽ�ˮ��������Խ������� (lib8.c) �õ���ͻ��֮
    ӡ�������ҵ���ʾд��ǽ�ϡ�ȡ�õ�һӡ���������ֱ�ӽ�����˹��������
    ��С������������ˮ���Թ��� 

	��������������̳���͵���������� (min*.c)���ش���˾���������
    �����˾�ɵ����Խ�����������������������ť����ͨ������ǽ��ȡ�ð�
    ��˹֮ӡ�� pray ���ɻ���˹�����ǡ� (��ʾ�ڷ����� bry ��������)

	����˹�����ǵķ������ҵ����ţ��Ѱ���˹ӡ�������ϣ��Ϳ��Դ���
    �ŵ����ﲨ���ǳ� (eda*.c) ����ȥ�������ﲨ���ǹ�����һ�������ϵĶ�
    �۹ֵ��۾�������Ų�����ӡ�ķ����Ȼ�� pray ����˹������ (����һ
    �� :p)��

	��������Ԩȥ (abyss*.c)��������Ԩ�ϲ������֮�ᣬ�������ε�����
    ȥ���Լ���Ѫ����ħ���󵽴�ڤ�����ش����ʹ�����⣬����ѡ�������
    ����ħ���Ϳ��Եõ�����˹֮ӡ���ص���˹�����ǻ�Զ���� *grin*

	����������л�԰ (g*.c)���߹������Թ� (ͨ������ʾ�Ƿ�Ů��֮ʥ��
    ǰ����Ҳ���� ...)���Ϳ���ȡ�ú�����ӡ����һ�رȽϼ򵥣�������������
    �ǡ�

	�������������� (wenro*.c) ȥ�������ʯ������Ů���� (ά��˹) ����
    ���������ʿ������ժ�����ڵ�����ǰ�ſ����׵����������Ҫ�ѿ�����
    ���Ļ���Ҳ�����ԣ�������˼���ǿ����΢ѷһ�㡣�õ�ϣ��˹ӡ��

	������ħ��ʦ�� (tower*.c)�������Թ��Ϳ����õ�����ķ�ӡ��Ȼ���
    ��鿲������� (p*.c) ��Ů����Mission Accomplished��ħ��ʦ�����Թ�����
    ���������ڣ�����������ÿ�� update room ֮����ڵķ�λ��ͬ��

III. NPC (���Ŀ¼ /u/l/lilia/ruin/monster)

1. ����ѧ�� ����Ŧ˹ (deltazeus.c)
   no_attack npc

2. ���˾ ���� (archbishop.c)
   str 25 int 30 dex 27 con 30 pie 20 kar 25 hp 1000 sp 2700
   aim_difficulty critical 100 weakest 100
   special_defense cold 90 fire 70 all 70 none 80
   spell heal 2 fireball 7
   skill dodge 70 
   ����ʩ�Ż��� < 0.3
   װ����˾�ۡ���ʥذ��
   װ���� ac 72 db 35 wc 95 dam 45-70

3. ������ʿ (deathknight.c)
   str 23 int 21 dex 23 con -- pie 21 kar 22 hp 5000 sp --
   skill dodge 100 longblade 100 parry 100
   killer
   װ����������
   װ���� ac 80 db 50 wc 113 dam 35-65
   ����֮�� (������ mob��Ŀ����Ҫ��ϲ��Ӳ������Ҳ�ʹ�Ľ�ѵ *grin*)

4. ����ʹ����ҵ� (archfiend.c)
   no_attack npc

5. ����ʫ�˼���˹ (bard.c)
   str 30 int 30 dex 20 con 25 pie 20 kar 20 hp 1200 sp --
   aim_difficulty critical 80 weakest 80
   special defense all 30 none 30 monk 20 scholar 20
   skill blunt 85 dodge 100
   װ����ɫ���ѣ����� (������½�Ǽ�)
   װ���� ac 40 db 42 wc 69 dam 35-65

6. ʥ��ʿ���� (carmue.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill longblade 100 dodge 100 parry 100
   װ����ħ��
   װ���� ac 157 db 53 wc 97 dam 35-70

7. ���� (ghost.c)
   no_attack npc

8. ʥ��ʿ���� (jitter.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill jousting 100 dodge 100 parry 100 block 100
   װ����ħǹ
   װ���� ac 157 db 56 wc 97 dam 35-70

9. ʥ��ʿ��ķ���� (emerald.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp 2000
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill polearm 100 dodge 100 parry 100 longblade 100
   װ������֮ŭ������Ļƻ衢�����ס���սѥ����ͷ�����ֻ�ϥ����ս�ס���ɫ����
   ( ����һ�����Ϊ /d/noden ������֮װ�� )
   װ���� ac 154 db 33 wc1 60 dam 22-35 wc2 25 dam 8-16

10. Ů�� (queen.c)
    no_attack npc


IV. ���� (���Ŀ¼ /u/l/lilia/ruin/weapon)

1. ��ħ�� (sword.c)
   wc 35 longblade dam 20-40 weight 250
   ��ʿר�ã������˲�����
   ���ʹ��ʱ��û���һ����ħ��
   ��ʦ�� npc ʹ��ʱ��û������׵���ħ��

2. ��ʥذ�� (holy_dagger.c)
   wc 40 dagger dam 25-40 weight 30
   �ع����� < 0.3
   �ع�����˺� 50�����㹫ʽ��˫����Ӫֵ���һǧΪ׼��������ӪΪ�����ɣ�
   ���ɵ��˺�Ϊ random(40)��ÿ���ع����� 10 �� spell_points��
   
3. �������� (scythe.c)
   wc 42 longblade dam 25-45 weight 150 no_sale no_second
   ����ò���������õ������� bug��

4. ��ɫ���� (flute.c)
   wc 35 blunt dam 10-25 weight 100
   �ع����� < 0.4
   �ع����� fire �˺��� 5

5. ��ħǹ (lance.c)
   wc 35 jousting dam 20-40 weight 250
   ��ʿר��
   ���ʹ��ʱ��û���һ����ħ��
   ��ʦ�� npc ʹ��ʱ��û������׵���ħ��

6. ����֮ŭ (polearm.c)
   wc 50 polearm dam 30-40 weight 245
   ��������֮�ƻ���� (���� .... �ٺ� .... ���� ....)
   �ع�����Ŀ�� 15 ������ 33% 9-15 �� 40% 9 ������ 80%
   �ع����� mental �˺��� 15 ������ 120 9-15 �� 140 ���� 250
   һ�����û��۶ϣ��۶���
   wc 30 polearm dam 14-28


V. ���� (���Ŀ¼ /u/l/lilia/ruin/armor)

1. ��ħ�� (plate.c)
   ac 35 db 6 body ��ʿ����ר��

2. ��ħ�� (helm.c)
   ac 8 db 3 head ��ʿ����ר��

3. ��ħ�� (arms.c)
   ac 4 db 4 arms ��ʿ����ר��

4. ��ħ�� (hands.c)
   ac 4 db 4 hands ��ʿ����ר��

5. ��ħ�� (leggings.c)
   ac 8 db 3 legs ��ʿ����ר��

6. ��ħЬ (feet.c)
   ac 8 db 3 feet ��ʿ����ר��

7. ��˾�� (bishop_robe.c)
   ac 22 db 5 body ҽ������ר�� weight 80 value 2000 silver

8. ��ħ�� (shield.c)
   ac 8 db 6 shield ��ʿ����ר��


VI. ������Ʒ (���Ŀ¼ /u/l/lilia/ruin/obj)

1. ħ���ֵ� (dictionary.c)
   ����ر���Ʒ�����������Ŧ˹��ȡ��


VII. ���ͼ��� (���Ŀ¼ /u/l/lilia/ruin/cmd)

1. ������ (_amass.c)
   sp -50 extra ac +10 db +(douin level)
   duration pie*3+50
   need skill: concentrate & douin

