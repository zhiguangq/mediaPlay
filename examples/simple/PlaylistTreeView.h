#ifndef PLAYLISTTREEVIEW_H
#define PLAYLISTTREEVIEW_H

#include <QListWidget>
#include <QImage>
#include <QLabel>
#include <QtGui>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollBar>
#include <QImage>
#include <QString>
#include <QList>
#include "dragicon.h"

class ProgramItem : public QWidget
{
	Q_OBJECT
public:
	ProgramItem(int id, QWidget *parent = 0);
	~ProgramItem();
	ProgramItem* clone();
	void init(QString itemName, QPixmap *image);
	void setMute(bool flag);
	inline bool getMute(void){ return m_isMute; }
	inline int getID(){ return m_id; }
signals:
	void activeItem(int id);
	void onMuteClick(int id, bool flag);
public slots:
	void onMuteClick();
	void onClick();
private:
	QString m_programName;

	DragIcon* m_programIcon;
	QPixmap* m_programPixmap;
	QPushButton* m_voiceButton;
	QLabel* m_programNameLabel;
	bool m_isMute;
	int m_id;
};

class PlaylistTreeView : public QWidget
{
	Q_OBJECT
public:
	PlaylistTreeView(QWidget *parent = 0);
	~PlaylistTreeView();

	void addItem(QString itemName, QImage *image);
	void clear(void);
	inline int getCurrentItem(void){ return m_activeItem; }
signals:
	void onItemMuteClick(int id, bool flag);
public slots:
	void valueChanged(int value);
	void activeItem(int id);
	void onMuteClick(int id, bool flag);
private:
	QHBoxLayout *m_mainLayout;
	QVBoxLayout *m_leftLayout;
	QScrollBar *m_scrollBar;
	QList<ProgramItem*> m_programList;
	QList<ProgramItem*> m_currentDisplayList;
	int m_displayNumber;
	int m_totalProbramNumber;
	int m_activeItem;
};

#endif


