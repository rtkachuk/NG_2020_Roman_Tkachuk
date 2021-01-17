#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer();

    m_file = new QMenu("Зырь сюда, да?");
    m_file_open = new QAction("Что будем орать?");

    m_file->addAction(m_file_open);
    ui->menubar->addMenu(m_file);

    ui->l_song_name->setText("Орать нечего");
    ui->s_progress->setValue(0);

    connect (m_file_open, &QAction::triggered, this, &Howl::openFile);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
    connect (ui->vs_volume, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
    connect (m_player, &QMediaPlayer::positionChanged, this, &Howl::calculatePosition);
    connect (ui->b_ff, &QPushButton::clicked, this, &Howl::fastForward);

    ui->listWidget->addItem("LOL");
}

Howl::~Howl()
{
    delete ui;
}

void Howl::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Что именно мы будем орать?", QDir::homePath(), "MP3 *.mp3");
    m_player->setMedia(QUrl::fromLocalFile(path));
    ui->l_song_name->setText(path.remove(0, path.lastIndexOf("/") + 1));
}

void Howl::play()
{
    m_player->play();
    ui->b_play->setText("||");
    disconnect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::pause);
}

void Howl::pause()
{
    m_player->pause();
    ui->b_play->setText(">");
    disconnect (ui->b_play, &QPushButton::clicked, this, &Howl::pause);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
}

void Howl::calculatePosition(qint64 position)
{
    if (m_player->duration() == 0)
        return;

    int progress = position / (m_player->duration() / 100);
    ui->s_progress->setValue(progress);
    qDebug() << "Current: " << position << " :::: Full: " << m_player->duration() << " :::: progress: " << progress;
}

void Howl::fastForward()
{
    m_player->setPosition(m_player->position() + 1000);
}

