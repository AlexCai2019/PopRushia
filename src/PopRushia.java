import javax.imageio.ImageIO;
import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;

public class PopRushia
{
	private static final ImageIcon closeIcon = new ImageIcon();
	private static final ImageIcon openIcon = new ImageIcon();
	private static final JLabel rushiaLabel = new JLabel(closeIcon);
	private static final JLabel countLabel = new JLabel("0", JLabel.CENTER);

	public static void main(String[] args) throws IOException
	{
		URL rushiaURL = PopRushia.class.getResource("pop_rushia.png");
		BufferedImage rushiaImage = rushiaURL != null ? ImageIO.read(rushiaURL) : new BufferedImage(1600, 800, BufferedImage.TYPE_INT_RGB);
		BufferedImage closeImage = rushiaImage.getSubimage(0, 0, 800, 800);
		BufferedImage openImage = rushiaImage.getSubimage(800, 0, 800, 800);

		closeIcon.setImage(closeImage);
		openIcon.setImage(openImage);

		rushiaLabel.addMouseListener(new ClickEvent());

		countLabel.setFont(new Font("Sans-Serif", Font.PLAIN, 64));

		JFrame frame = new JFrame("Pop Rushia");
		frame.setSize(1600, 900);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		URL iconURL = PopRushia.class.getResource("icon.png");
		frame.setIconImage(iconURL != null ? ImageIO.read(iconURL) : new BufferedImage(1600, 800, BufferedImage.TYPE_INT_RGB));
		frame.add(rushiaLabel, BorderLayout.CENTER);
		frame.add(countLabel, BorderLayout.NORTH);
		frame.setVisible(true);
	}

	private static class ClickEvent implements MouseListener
	{
		private long count = 0L;

		@Override
		public void mousePressed(MouseEvent event)
		{
			rushiaLabel.setIcon(openIcon);
			countLabel.setText(Long.toString(++count));

			URL soundURL = PopRushia.class.getResource("rushia.wav");
			try (AudioInputStream audioStream = soundURL != null ? AudioSystem.getAudioInputStream(soundURL) : (AudioInputStream) AudioInputStream.nullInputStream())
			{
				Clip rushiaClip = AudioSystem.getClip();
				rushiaClip.open(audioStream);
				rushiaClip.start();
			}
			catch (IOException | UnsupportedAudioFileException | LineUnavailableException exception)
			{
				throw new RuntimeException(exception);
			}
		}

		@Override
		public void mouseReleased(MouseEvent event)
		{
			rushiaLabel.setIcon(closeIcon);
		}

		@Override
		public void mouseClicked(MouseEvent event) {}

		@Override
		public void mouseEntered(MouseEvent event) {}

		@Override
		public void mouseExited(MouseEvent event) {}
	}
}